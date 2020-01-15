import org.apache.poi.openxml4j.opc.OPCPackage;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.WorkbookUtil;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.*;

public class Users {
    public static void openUserOper(long userId, String userName) throws IOException {
        InputStream inp = new FileInputStream("users.xlsx");
        Workbook wb = WorkbookFactory.create(inp);
        Sheet sheet = wb.getSheetAt(0);
        Row row=sheet.createRow(sheet.getLastRowNum()+1);
        Cell cell = row.getCell(0);
        if (cell == null) {
            row.createCell(0).setCellValue(userId);
            row.createCell(1).setCellValue(userName);
        }
        OutputStream fileOut = new FileOutputStream("users.xlsx");
        wb.write(fileOut);
    }

    public static boolean checkUser(long userId) throws IOException{
        DataFormatter formatter = new DataFormatter();
        boolean result =false;
        InputStream inp = new FileInputStream("users.xlsx");
        Workbook wb = WorkbookFactory.create(inp);
        Sheet sheet = wb.getSheetAt(0);
        for (Row row : sheet) {
            if (formatter.formatCellValue(row.getCell(0)).equals(Long.toString(userId))) {
                result=true;
            }
        }
        return result;
    }
}
