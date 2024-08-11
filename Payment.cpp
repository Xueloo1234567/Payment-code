#include <iostream>
using namespace std;

const int maxItems = 5; // Limit of availableItems
const int maxOrder = 20; // Limit of order

string availableItems[maxItems] = { "Panadol", "Aspirin", "Claritin", "Zyrtec", "Imodium" };
double itemPrices[maxItems] = { 5.50, 8.70, 20, 23.20, 17.30 };

double wallet = 1000;

void Payment(int orderCount, string orderItems[], int orderQuantities[], double orderPrices[])
{
    // Select payment method
    int select;

    do
    {
        system("cls");

        cout << "Select your payment method: \n"
            << "1. Credit/Debit Card\n"
            << "2. Touch n go\n"
            << "3. Cash\n" << endl;
        cout << "Enter your select number: ";
        cin >> select;

        switch (select)
        {
        case 1:
            cout << "You selected Credit/Debit Card\n" << endl;
            break;
        case 2:
            cout << "You selected Touch n go\n" << endl;
            break;
        case 3:
            cout << "You selected Cash\n" << endl;
            break;
        default:
            cout << "Invalid number\n" << endl;
            break;
        }
        system("pause");

    } while (select <= 0 || select > 3);

    // Review Invoice
    system("cls");

    double totalPrice = 0; // for store the sum of all 
    cout << "Review your invoice:" << endl;
    for (int i = 0; i < orderCount; ++i)
    {
        double itemTotalPrice = orderQuantities[i] * orderPrices[i];
        cout << "Item Name: " << orderItems[i] << endl;
        cout << "Quantity: " << orderQuantities[i] << endl;
        cout << "Price per item: $" << orderPrices[i] << endl;
        cout << "Total Price for this item: $" << itemTotalPrice << endl;
        totalPrice += itemTotalPrice; // Update total
        cout << endl;
    }
    cout << "Total Price for all items: $" << totalPrice << endl;

    // Press Y to Pay, N to cancel order
    char payOrCancel;
    cout << "Press Y to Pay, N to cancel order: ";
    cin >> payOrCancel;

    if (payOrCancel == 'Y' || payOrCancel == 'y')
    {
        if (wallet >= totalPrice)
        {
            wallet -= totalPrice;
            cout << "Payment successful! Your remaining balance is $" << wallet << endl;
        }
        else
        {
            cout << "Insufficient funds. Payment failed.\n";
        }
    }
    else if (payOrCancel == 'N' || payOrCancel == 'n')
    {
        cout << "Order canceled.\n";
    }
    else
    {
        cout << "Invalid input. Please try again.\n";
    }

    // Review Receipt
    if (payOrCancel == 'Y' || payOrCancel == 'y')
    {
        system("cls");
        cout << "Receipt:\n" << endl;
        for (int i = 0; i < orderCount; ++i)
        {
            cout << "Item Name: " << orderItems[i] << endl;
            cout << "Quantity: " << orderQuantities[i] << endl;
            cout << "Price per item: $" << orderPrices[i] << endl;
            cout << endl;
        }
        cout << "Total Price: $" << totalPrice << endl;
        cout << "Your wallet remain: $" << wallet << endl;
        cout << endl;
    }
}

int main()
{
    // Create empty orders
    string orderItems[maxOrder];
    int orderQuantities[maxOrder];
    double orderPrices[maxOrder];
    int orderCount = 0;

    // Display all menu's order
    cout << "Available items:\n";
    for (int i = 0; i < maxItems; ++i)
    {
        cout << i + 1 << ". " << availableItems[i] << " - $" << itemPrices[i] << endl;
    }

    char addmore = 'N';
    do
    {
        int itemIndex;
        cout << "\nEnter the number of the food item you want to order: ";
        cin >> itemIndex;

        if (itemIndex < 1 || itemIndex > maxItems) {
            cout << "Invalid item number. Please try again.\n";
            continue; // Back to start of "do"
        }

        int quantity;
        cout << "Enter quantity: ";
        cin >> quantity;

        // Store order details
        orderItems[orderCount] = availableItems[itemIndex - 1];
        orderQuantities[orderCount] = quantity;
        orderPrices[orderCount] = itemPrices[itemIndex - 1];

        orderCount++;

        cout << "Do you want to add another item? (Y/N): ";
        cin >> addmore;
    } while ((addmore == 'Y' || addmore == 'y') && orderCount < maxOrder);

    Payment(orderCount, orderItems, orderQuantities, orderPrices);

    return 0;
}
