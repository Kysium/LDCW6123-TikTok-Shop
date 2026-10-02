#include <iostream>
#include <limits>
#include <string> // Added to support text input for promo codes

using namespace std;

int main() {
    int choice;
    int quantity;
    int totalItems = 0;
    int totalCents = 0;
    string promoCode; // Variable to store user's live-stream promo code

    cout << "=== TikTok Shop Shopping Cart Demo ===\n";
    cout << "An educational simulation of in-app shopping.\n";

    while (true) {
        // Display TikTok Shop product catalog
        cout << "\n1. Phone Case    - RM 15.00\n";
        cout << "2. Wireless Mouse - RM 35.00\n";
        cout << "3. Tote Bag      - RM 20.00\n";
        cout << "4. View cart\n";
        cout << "5. Checkout and exit\n";
        cout << "Choose an option (1-5): ";

        // Reject non-numeric input and allow another attempt
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        int priceCents = 0;

        // Process user product selection using a switch statement
        switch (choice) {
            case 1:
                priceCents = 1500;
                break;
            case 2:
                priceCents = 3500;
                break;
            case 3:
                priceCents = 2000;
                break;
            case 4:
                cout << "\n--- Cart Summary ---\n";
                cout << "Items in cart: " << totalItems << "\n";
                cout << "Cart total: RM " << totalCents / 100 << ".00\n";
                continue;
            case 5:
                if (totalItems == 0) {
                    cout << "Your cart is empty. Goodbye!\n";
                } else {
                    // Promo Code & Checkout Logic (if/else integration)
                    cout << "\n--- TikTok Shop Checkout ---\n";
                    cout << "Do you have a live-stream promo code? (Enter code or type 'NO'): ";
                    cin >> promoCode;
                    
                    int discountCents = 0;
                    if (promoCode == "LIVE20") {
                        cout << "Promo code applied! 20% off your total.\n";
                        discountCents = (totalCents * 20) / 100;
                    } else if (promoCode != "NO" && promoCode != "no") {
                        cout << "Invalid promo code. Proceeding without discount.\n";
                    }

                    int finalTotalCents = totalCents - discountCents;

                    // Final Order Receipt
                    cout << "\n=== Order Receipt ===\n";
                    cout << "Total items: " << totalItems << "\n";
                    cout << "Subtotal: RM " << totalCents / 100 << ".00\n";
                    if (discountCents > 0) {
                        cout << "Discount: -RM " << discountCents / 100 << ".00\n";
                    }
                    cout << "Total payment: RM " << finalTotalCents / 100 << ".00\n";
                    cout << "Demo checkout complete. Thank you!\n";
                }
                return 0;
            default:
                cout << "Please choose an option from 1 to 5.\n";
                continue;
        }

        cout << "Enter quantity (1-99): ";

        if (!(cin >> quantity)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid quantity. Please enter a number.\n";
            continue;
        }

        if (quantity < 1 || quantity > 99) {
            cout << "Quantity must be between 1 and 99.\n";
            continue;
        }

        // Limit the cart size and calculate prices in cents
        if (totalItems + quantity > 999) {
            cout << "The cart can hold at most 999 items.\n";
            continue;
        }

        totalItems += quantity;
        totalCents += priceCents * quantity;

        cout << "Added " << quantity << " item(s) to your cart.\n";

        // TikTok Algorithm Advertisement Feature
        cout << "\n[TikTok Algorithm Suggests] ";
        if (choice == 1) {
            cout << "Since you bought a Phone Case, check out our wireless chargers!\n";
        } else if (choice == 2) {
            cout << "Shoppers who bought a Mouse also loved our RGB keyboards!\n";
        } else if (choice == 3) {
            cout << "Pair that Tote Bag with some cute enamel pins available on TikTok Shop!\n";
        }
    }

    return 0;
}