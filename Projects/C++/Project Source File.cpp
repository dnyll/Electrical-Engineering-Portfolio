#include <iostream>
using namespace std;
int main() {

    char choice;
    double angle;
    bool continueProgram = true;

    do {
        cout << "Select a trigonometric function (S/s for Sin, C/c for Cos, T/t for Tan): ";
        cin >> choice;

        switch (choice) {
            case 'S':
            case 's':
                cout << "Enter the angle in degrees (-90 to 90): ";
                cin >> angle;

                if (angle >= -90 && angle <= 90) {
                    double radians = angle * 3.14159265358979323846 / 180.0;
                    double result = radians;

                    double term = radians;
                    int n = 3;
                    int sign = -1;

                    while (term >= 0.000001 || term <= -0.000001) {
                        term = term * radians * radians / (n * (n - 1));
                        result += sign * term;

                        sign *= -1;
                        n += 2;
                    }

                    cout << "Sin(" << angle << ") = " << result << endl;
                } else {
                    cout << "'Error' The angle is outside the valid range." << endl;
                }
                break;

            case 'C':
            case 'c':
                cout << "Enter the angle in degrees (-90 to 90): ";
                cin >> angle;

                if (angle >= -90 && angle <= 90) {
                    double radians = angle * 3.14159265358979323846 / 180.0;
                    double result = 1.0;

                    double term = 1.0;
                    int n = 2;
                    int sign = -1;

                    while (term >= 0.000001 || term <= -0.000001) {
                        term = term * radians * radians / (n * (n - 1));
                        result += sign * term;

                        sign *= -1;
                        n += 2;
                    }

                    cout << "Cos(" << angle << ") = " << result << endl;
                } else {
                    cout << "'Error' The angle is outside the valid range." << endl;
                }
                break;

            case 'T':
            case 't':
                cout << "Enter the angle in degrees (-90 to 90): ";
                cin >> angle;

                if (angle >= -90 && angle <= 90) {
                    double radians = angle * 3.14159265358979323846 / 180.0;
                    double sin = radians;

                    double term = radians;
                    int n = 3;
                    int sign = -1;

                    while (term >= 0.000001 || term <= -0.000001) {
                        term = term * radians * radians / (n * (n - 1));
                        sin += sign * term;

                        sign *= -1;
                        n += 2;
                    }

                    double cos = 1.0;
                    term = 1.0;
                    n = 2;
                    sign = -1;

                    while (term >= 0.000001 || term <= -0.000001) {
                        term = term * radians * radians / (n * (n - 1));
                        cos += sign * term;

                        sign *= -1;
                        n += 2;
                    }

                    double tan = sin / cos;

                    cout << "Tan(" << angle << ") = " << tan << endl;
                } else {
                    cout << "'Error' The angle is outside the valid range." << endl;
                }
                break;

            default:
                cout << "'Error'... Invalid choice." << endl;
                break;
        }

        char continueChoice;
        cout << "Do you want to compute any other trigonometric function? (Y/y to continue, any other key to exit): ";
        cin >> continueChoice;

        if (continueChoice != 'Y' && continueChoice != 'y') {
            continueProgram = false;
        }
    } while (continueProgram);

    return 0;
}
