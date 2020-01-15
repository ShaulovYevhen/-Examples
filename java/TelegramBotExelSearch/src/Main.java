import org.telegram.telegrambots.ApiContextInitializer;
import org.telegram.telegrambots.TelegramBotsApi;
import org.telegram.telegrambots.exceptions.TelegramApiRequestException;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        JFrame jFrame = getFrame();
    }
    static JFrame getFrame() throws IOException {
        JFrame jFrame = new JFrame();
        jFrame.setTitle("BiggerTelleBot");
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        JLabel jLabel = new JLabel();
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        jFrame.setBounds(dimension.width / 2 - 250, dimension.height / 2 - 150, 400, 300);
        JButton button = new JButton("Start bot");
        jFrame.getContentPane().add(button, BorderLayout.SOUTH);
        if (InternetAvailabilityChecker.isInternetAvailable()){
            jLabel.setText("<html><font size = +2>Интернет доступен</font></html>");
            jFrame.add(jLabel, BorderLayout.NORTH);
            button.setVisible(true);
        } else {
            jLabel.setText("<html><font size = +2>Нет доступа к интернету, восстановите доступ и перезапустите программу</font></html>");
            jFrame.getContentPane().add(jLabel, BorderLayout.NORTH);
            button.setVisible(false);
        }
        button.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                jLabel.setText(("<html><font size = +2>Бот запущен. Для отключения закройте окно программы.</font></html>"));
                jFrame.getContentPane().add(jLabel, BorderLayout.NORTH);
                button.setVisible(false);
                ApiContextInitializer.init();
                TelegramBotsApi telegramBotsApi = new TelegramBotsApi();
                try {
                    telegramBotsApi.registerBot(new Bot());
                } catch (TelegramApiRequestException w) {
                    w.printStackTrace();
                }
            }
        });
        return jFrame;
    }

}
