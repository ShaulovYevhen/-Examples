import org.apache.poi.ss.usermodel.DataFormatter;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.telegram.telegrambots.api.methods.send.SendMessage;
import org.telegram.telegrambots.api.objects.Message;
import org.telegram.telegrambots.api.objects.Update;
import org.telegram.telegrambots.api.objects.replykeyboard.ReplyKeyboardMarkup;
import org.telegram.telegrambots.api.objects.replykeyboard.buttons.KeyboardButton;
import org.telegram.telegrambots.api.objects.replykeyboard.buttons.KeyboardRow;
import org.telegram.telegrambots.bots.TelegramLongPollingBot;
import org.telegram.telegrambots.exceptions.TelegramApiException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Bot extends TelegramLongPollingBot {
    private int colValue = 0;
    private Boolean caseOn = true;

    @Override
    public void onUpdateReceived(Update update) {
        Message message = update.getMessage();
        if (message != null && message.hasText()) {
            String userName = message.getChat().getFirstName() + " " + message.getChat().getLastName();
            long userId = message.getChat().getId();
            try {
                if (Users.checkUser(userId)){
                    cases(message);
                }
                else {
                            Users.openUserOper(userId, userName);
                            sendMsg(message, "1. Выберете что искать.\n2. Введите что искать.",caseOn);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    private void cases(Message message) {
        if (caseOn) {
            switch (message.getText()) {
                case "Помощ":
                    sendMsg(message, "1. Выберете что искать.\n2. Введите что искать.",caseOn);
                    break;
                case "ФИО":
                    colValue = 0;
                    sendMsg(message, "Введите ФИО c клавиатуры(регистр не учитывается)",caseOn);
                    caseOn = false;
                    break;
                case "Фирма":
                    colValue = 1;
                    sendMsg(message, "Введите название фирмы c клавиатуры",caseOn);
                    caseOn = false;
                    break;
                case "Телефон":
                    colValue = 2;
                    sendMsg(message, "Введите телефон c клавиатуры",caseOn);
                    caseOn = false;
                    break;
                case "E-mail":
                    colValue = 3;
                    caseOn = false;
                    sendMsg(message, "Введите E-mail c клавиатуры",caseOn);
                    break;
                default:
                    sendMsg(message, "Ошибка! Выберите что искать ниже!",caseOn);
            }
        } else {
            caseOn = true;
            try {
                    search(message, colValue);
                    sendMsg(message, "Выберите что искать",caseOn);
            } catch (IOException e) {
                e.printStackTrace();
                sendMsg(message, "Нет таких \nВыберете что искать",caseOn);
            }
        }
    }
    private void sendMsg(Message message, String s, boolean caseOn) {
        SendMessage sendMessage = new SendMessage();
        sendMessage.setChatId(message.getChatId().toString());
        sendMessage.setText(s);
        try {
            if (caseOn){
            setButtons(sendMessage);
            }
            sendMessage(sendMessage);
        } catch (TelegramApiException e) {
            e.printStackTrace();
        }
    }
    private void search(Message message, int colValue) throws IOException {
        int count = 50;
        boolean result = true;
        String cellValue;
        String searchValue=message.getText();
        DataFormatter formatter = new DataFormatter();
        Sheet sheet = ExelOperations.openExelFile();
        if (searchValue.length()<3){
            sendMsg(message,"Минимумм 3 символа",true);
        }else {
            for (Row row : sheet) {
                cellValue = formatter.formatCellValue(row.getCell(colValue));
                cellValue = cellValue.toUpperCase();
                if (cellValue.toUpperCase().contains(searchValue.toUpperCase())) {
                    result = false;
                    sendMsg(message, "\nФИО: " + sheet.getRow(row.getRowNum()).getCell(0) + "\n" +
                            "Фирма: " + sheet.getRow(row.getRowNum()).getCell(1) + "\n" +
                            "Телефон: " + formatter.formatCellValue(sheet.getRow(row.getRowNum()).getCell(2)) + "\n" +
                            "Email: " + sheet.getRow(row.getRowNum()).getCell(3) + "\n", true);
                    count--;
                    if (count==0){
                        sendMsg(message, "Слишком много совпадений", false);
                        break;
                    }
                }
            }
            if (result) sendMsg(message,"нет таких", true);
        }
    }
    private void setButtons(SendMessage sendMessage) {
            ReplyKeyboardMarkup replyKeyboardMarkup = new ReplyKeyboardMarkup();
            sendMessage.setReplyMarkup(replyKeyboardMarkup);
            replyKeyboardMarkup.setSelective(true);
            replyKeyboardMarkup.setResizeKeyboard(true);
            replyKeyboardMarkup.setOneTimeKeyboard(false);
            List<KeyboardRow> keyboardRowList = new ArrayList<>();
            KeyboardRow keyboardFirstRow = new KeyboardRow();
            keyboardFirstRow.add(new KeyboardButton("ФИО"));
            keyboardFirstRow.add(new KeyboardButton("Телефон"));
            keyboardFirstRow.add(new KeyboardButton("Фирма"));
            keyboardFirstRow.add(new KeyboardButton("E-mail"));
            keyboardRowList.add(keyboardFirstRow);
            replyKeyboardMarkup.setKeyboard(keyboardRowList);
    }

    @Override
    public String getBotUsername() {
        return "BiggerTelleBot";
    }

    @Override
    public String getBotToken() {
        return "910959073:AAEG1DpwEh4bkhm4Ol0g_QSCqgVadD0s9Dg";
    }
}
