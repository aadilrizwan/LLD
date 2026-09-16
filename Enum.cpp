// Order Processing System - two enums: OrderStatus and PaymentMethod.
#include <bits/stdc++.h>
using namespace std;

enum class OrderStatus {
    Pending,
    Processing,
    Shipped,
    Delivered,
    Cancelled
};

string orderStatusToString(OrderStatus status) {
    switch (status) {
        case OrderStatus::Pending: return "Pending";
        case OrderStatus::Processing: return "Processing";
        case OrderStatus::Shipped: return "Shipped";
        case OrderStatus::Delivered: return "Delivered";
        case OrderStatus::Cancelled: return "Cancelled";
    }
    return "Unknown";
}
enum class PaymentMethod {
    CreditCard,
    DebitCard,
    PayPal,
    BankTransfer,
    CashOnDelivery
};

string paymentMethodToString(PaymentMethod method) {
    switch (method) {

        case PaymentMethod::CreditCard: return "Credit Card";
        case PaymentMethod::DebitCard: return "Debit Card";
        case PaymentMethod::PayPal: return "PayPal";
        case PaymentMethod::BankTransfer: return "Bank Transfer";
        case PaymentMethod::CashOnDelivery: return "Cash on Delivery";
    }
    return "Unknown";
}
class Order {
private:
    int orderId;
    OrderStatus status;
    PaymentMethod paymentMethod;
    double amount;

public:
    Order(int id, OrderStatus stat, PaymentMethod payMethod, double amt) : orderId(id),
    status(stat), paymentMethod(payMethod), amount(amt){}

    bool advanceStatus() {
        switch (status) {
            case OrderStatus::Pending:
                status = OrderStatus::Processing;
                return true;
            case OrderStatus::Processing:
                status = OrderStatus::Shipped;
                return true;
            case OrderStatus::Shipped:
                status = OrderStatus::Delivered;
                return true;
            case OrderStatus::Delivered:
                return false;
            case OrderStatus::Cancelled:
                return false;
        }
        return false;
    }

    bool cancelOrder() {
        if (status == OrderStatus::Pending || status == OrderStatus::Processing){
            status = OrderStatus::Cancelled;
            return true;
        }
        return false;
    }

    double calculateDiscount(double discountRate) {
        if (discountRate < 0 || discountRate > 1) {
            throw invalid_argument(
                "Discount rate must be between 0 and 1."
            );
        }
        return amount * (1 - discountRate);
    }

    void displayOrderDetails() {

        cout << "-----------------------------\n";
        cout << "Order ID: " << orderId << '\n';
        cout << "Status: " << orderStatusToString(status) << '\n';
        cout << "Payment Method: " << paymentMethodToString(paymentMethod)  << '\n';
        cout << "Amount: $" << fixed << setprecision(2) << amount << '\n';
        cout << "-----------------------------\n";
    }
};

int main() {
    Order order1( 101, OrderStatus::Pending, PaymentMethod::CreditCard, 150.00 );

    cout << "Initial Order:\n";
    order1.displayOrderDetails();

    cout << "\nAdvancing order status...\n";

    if (order1.advanceStatus()) cout << "Order status advanced successfully.\n";
    else cout << "Order status cannot be advanced.\n";
    
    order1.displayOrderDetails();

    cout << "\nCalculating discounted amount (10% discount)...\n";

    try {
        double discountedAmount = order1.calculateDiscount(0.10);
        cout << "Discounted Amount: $" << fixed << setprecision(2) << discountedAmount << '\n';
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << '\n';
    }

    cout << "\nCancelling the order...\n";

    if (order1.cancelOrder()) cout << "Order cancelled successfully.\n";
    else  cout << "Order cannot be cancelled.\n";

    order1.displayOrderDetails();

    return 0;
}