#include "../include/create_main_wnd_table.h"
#include "../include/create_operations_page.h"

static uiTableModelHandler handler;
static uiTableModel *model;

static int modelNumColums(uiTableModelHandler *handler, uiTableModel *model)
{
    return COLS_TOTAL;
}

static int modelNumRows(uiTableModelHandler *handler, uiTableModel *model)
{
    return CARDS_TOTAL;
}

static uiTableValueType modelColumnType(uiTableModelHandler *handler, uiTableModel *model, int column)
{
	return uiTableValueTypeString;
}

static uiTableValue *modelCellValue(uiTableModelHandler *handler, uiTableModel *model, int row, int col)
{
    char buf[256];

    if (col == 0)
    {
        switch (row)
        {
            case 0:
                strcpy(buf, "\n\n\t         Oleneff Platinum\n\n");
                break;
            case 1:
                strcpy(buf, "\n\n\t\t   Oleneff Black\n\n");
                break;
            case 2:
                strcpy(buf, "\n\n\t\t       Visa Gold\n\n");
                break;
            case 3:
                strcpy(buf, "\n\n\t    Master Card Business\n\n");
                break;
            case 4:
                strcpy(buf, "\n\n\t\t     Oleneff Kids\n\n");
                break;
        }

        return uiNewTableValueString(buf);
    }

    if (col == 1)
    {
        switch (row)
        {
            case 0:
                strcpy(buf, "\n\n\t\t      37456.34 р.\n\n");
                break;
            case 1:
                strcpy(buf, "\n\n\t\t      11400.79 р.\n\n");
                break;
            case 2:
                strcpy(buf, "\n\n\t\t      14374.23 р.\n\n");
                break;
            case 3:
                strcpy(buf, "\n\n\t\t       3987.67 р.\n\n");
                break;
            case 4:
                strcpy(buf, "\n\n\t\t       7984.32 р.\n\n");
                break;
        }

        return uiNewTableValueString(buf);
    }

    if (col == 3)
    {
        return uiNewTableValueString("\n\nОперации\n\n");
    }

    return uiNewTableValueString(buf);
}

static void modelSetCellValue(uiTableModelHandler *handler, uiTableModel *model, int row, int col, const uiTableValue *val)
{
    char balance[100];

    switch (row)
    {
        case 0:
            strcpy(balance, "37456.34");
            break;
        case 1:
            strcpy(balance, "11400.79");
            break;
        case 2:
            strcpy(balance, "14374.23");
            break;
        case 3:
            strcpy(balance, "3987.67");
            break;
        case 4:
            strcpy(balance, "7984.32");
            break;
    }

    createOperationsPage(balance);
}

uiControl *createMainWndTable(void)
{
    uiBox *hBox;
    uiTable *mainWndTable;
    uiTableParams params;
    uiGrid *grid;
    uiLabel *space;
    uiEntry *findEntry;

    hBox = uiNewHorizontalBox();
    grid = uiNewGrid();
    uiGridSetPadded(grid, 1);
    uiBoxAppend(hBox, uiControl(grid), 0);

    handler.NumColumns = modelNumColums;
    handler.NumRows = modelNumRows;
    handler.ColumnType = modelColumnType;
    handler.CellValue = modelCellValue;
    handler.SetCellValue = modelSetCellValue;

    model = uiNewTableModel(&handler);

    memset(&params, 0, sizeof(uiTableParams));
    params.Model = model;
    params.RowBackgroundColorModelColumn = 3;
    mainWndTable = uiNewTable(&params);

    uiTableAppendTextColumn(mainWndTable, "\n\t\t\tКарта \t\t\t\n", 0, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendTextColumn(mainWndTable, "\n\t\t\t Баланс          \t\t\n", 1, uiTableModelColumnNeverEditable, NULL);
    uiTableAppendButtonColumn(mainWndTable, "\n\t\t\t  К операциям \t\n", 3, 1);

    space = uiNewLabel("");
    findEntry = uiNewFindEntry();
    uiGridAppend(grid, uiControl(findEntry), 22, 10, 40, 10, 1, uiAlignCenter, 0, uiAlignCenter);
    uiGridAppend(grid, uiControl(space), 0, 5, 55, 13, 1, uiAlignCenter, 0, uiAlignCenter);
    uiGridAppend(grid, uiControl(mainWndTable), 8, 20, 70, 77, 1, uiAlignFill, 0, uiAlignFill);

    return uiControl(hBox);
}
