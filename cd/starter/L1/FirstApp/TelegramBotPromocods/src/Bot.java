import org.telegram.telegrambots.ApiContextInitializer;
import org.telegram.telegrambots.TelegramBotsApi;
import org.telegram.telegrambots.api.methods.send.SendMessage;
import org.telegram.telegrambots.api.objects.Message;
import org.telegram.telegrambots.api.objects.Update;
import org.telegram.telegrambots.bots.TelegramLongPollingBot;
import org.telegram.telegrambots.exceptions.TelegramApiException;
import org.telegram.telegrambots.exceptions.TelegramApiRequestException;

public class Bot extends TelegramLongPollingBot {

    private long name = 0;

    @Override
    public void onUpdateReceived(Update update) {
        Message message = update.getMessage();
        if (message != null && message.hasText()){
            if (message.getText().equals("/help")){
                sendMsg(message, "Привет "+message.getChat().getFirstName());
            }
            if (message.getText().equals("/code")){
                if (name!=message.getChat().getId()){
                    sendMsg(message,Code.CodeCreate(6));
                    name=message.getChat().getId();
                }
                else
                    sendMsg(message, "Вы уже использовали свой промо код");
            }
            else {
                sendMsg(message, "Я тестовый бот");
            }
        }
    }
    private void sendMsg(Message message, String s){
        SendMessage sendMessage = new SendMessage();
      //  sendMessage.enableMarkdown(true);
        sendMessage.setChatId(message.getChatId().toString());
      //  sendMessage.setReplyToMessageId(message.getMessageId());
        sendMessage.setText(s);
        try {
            sendMessage(sendMessage);
        }catch (TelegramApiException e) {
            e.printStackTrace();
        }
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
