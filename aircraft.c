#include "aircraft.h"

int main()
{
    int choose;
    Flights flights;
    Orders orders;
    flights.length = 0;
    orders.length = 0;
    Welcome();
    Open_Flights(&flights, READ);
    Open_Orders(&orders, READ);
    do
    {
        printf("**********************\n");
        printf("*  �������ʾ��ɲ���  *\n");
        printf("* 1-------------��ѯ *\n");
        printf("* 2-------------��Ʊ *\n");
        printf("* 3-------------��Ʊ *\n");
        printf("* 4-------------�޸� *\n");
        printf("* 5-------------�˳� *\n");
        printf("**********************\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            Search(&flights, &orders);
            break;
        case 2:
            Reserve(&flights, &orders);
            break;
        case 3:
            Withdraw(&flights, &orders);
            break;
        // case 4:
        //     Adjust(&flights);
        //     break;
        case 5:
            break;
        default:
            printf("\t�޴˹��ܣ�����������!\n");
            break;
        }
    } while (choose != 5);
}