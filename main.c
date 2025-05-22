#include <stdio.h>

int main()
{
    int array[100], n = 0, option;

    for (int loop = 0; loop < 100; loop++)
        {
        printf("\n1.Input\n2.Update\n3.Delete\n4.Display\n");
        printf("5.Sort\n6.Search\n7.Exit\n--Choose--");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
                printf("Enter size (1-100): ");
                scanf("%d", &n);
                if (n < 1 || n > 100)
                {
                    printf("Invalid size.\n");
                    n = 0;
                    break;
                }
                for (int i = 0; i < n; i++)
                {
                    printf("array[%d]: ", i);
                    scanf("%d", &array[i]);
                }
                break;
            }

            case 2:
            {
                int idx;
                printf("Enter index (0 to %d): ", n - 1);
                scanf("%d", &idx);
                if (idx >= 0 && idx < n)
                {
                    printf("New value: ");
                    scanf("%d", &array[idx]);
                } else
                {
                    printf("Invalid index.\n");
                }
                break;
            }

            case 3:
                {
                int val, found = 0;
                printf("Enter value to delete: ");
                scanf("%d", &val);
                for (int i = 0; i < n; i++)
                {
                    if (array[i] == val)
                    {
                        for (int j = i; j < n - 1; j++)
                            array[j] = array[j + 1];
                        n--;
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Value not found.\n");
                break;
            }

            case 4:
            {
                if (n == 0) printf("Array is empty.\n");
                else
                {
                    printf("Array: ");
                    for (int i = 0; i < n; i++)
                        printf("%d ", array[i]);
                    printf("\n");
                }
                break;
            }

            case 5:
            {
                char type;
                printf("Sort (A/D): ");
                scanf(" %c", &type);
                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        int swap = 0;
                        if ((type == 'A' || type == 'a') && array[i] > array[j])
                            swap = 1;
                        else if ((type == 'D' || type == 'd') && array[i] < array[j])
                            swap = 1;
                        if (swap)
                        {
                            int temp = array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                break;
            }

            case 6:
            {
                int val, found = 0;
                printf("Enter value to search: ");
                scanf("%d", &val);
                for (int i = 0; i < n; i++)
                {
                    if (array[i] == val)
                    {
                        printf("Found at index %d\n", i);
                        found = 1;
                    }
                }
                if (!found) printf("Not found.\n");
                break;
            }

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
