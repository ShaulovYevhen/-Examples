import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import java.io.IOException;
import java.io.FileInputStream;

public class ExelOperations{
    static Sheet openExelFile() throws IOException {
        FileInputStream fis = new FileInputStream("baze.xlsx");
        Workbook wb = new XSSFWorkbook(fis);
        Sheet sheet = wb.getSheetAt(0);
        fis.close();
        return sheet;
    }
}

