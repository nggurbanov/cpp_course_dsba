/*
Реализуйте систему обработки заказов, которая проверяет 
корректность введенного количества товаров и их стоимости. 
Если количество товаров отрицательное или стоимость товара 
ниже допустимого предела, система должна генерировать исключения.

Требования к реализации:
Определение класса исключения: Создайте класс исключения 
OrderException, который наследуется от std::exception. 
Класс должен содержать два поля: сообщение об ошибке и код ошибки.
 Реализуйте конструктор, принимающий эти параметры, и методы для их 
 извлечения.

Функция обработки заказа: Реализуйте функцию processOrder, 
которая принимает количество товаров и их стоимость как аргументы. 
Функция должна проверять, что количество товаров не отрицательно 
 что стоимость товара не ниже минимально допустимой. В случае
  обнаружения ошибки, функция должна генерировать исключение 
  OrderException с соответствующим сообщением об ошибке и кодом ошибки.

Обработка исключений: В функции main, вызовите processOrder с
 различными параметрами для демонстрации работы системы. 
 Используйте блоки try-catch для обработки исключений, 
 генерируемых функцией processOrder. При перехвате исключения, 
  выводите информацию об ошибке и код ошибки.
*/

#include <iostream>
#include <stdexcept>
#include <string>

class OrderException : public std::exception {
public:
    explicit OrderException(const std::string& message, int errorCode)
        : msg_(message), code_(errorCode) {}

    const char* what() const noexcept override {
        return msg_.c_str();
    }

    int getErrorCode() const noexcept {
        return code_;
    }

private:
    std::string msg_;
    int code_;
};

void processOrder(int quantity, double price) {
    if (quantity < 0) {
        throw OrderException("Negative quantity is not allowed", 1);
    }
    if (price < 10.0) {
        throw OrderException("Price is below the minimum allowed", 2);
    }
    std::cout << "Order processed successfully\n";
}

int main() {
    try {
        processOrder(-99, 12.0);
    } catch (const OrderException& e) {
        std::cout << "Exception: " << e.what() << "\nError code: " << e.getErrorCode() << std::endl;
    }

    try {
        processOrder(10, 5.0);
    } catch (const OrderException& e) {
        std::cout << "Exception: " << e.what() << "\nError code: " << e.getErrorCode() << std::endl;
    }

    return 0;
}
