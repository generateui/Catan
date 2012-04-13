#include <QtCore>

void get_digits(double x);

int main(int argc, char *argv[]){
	if (argc == 2){
            QString word = argv[1];
            bool ok = true;
            double value = word.toDouble(&ok);
            get_digits(value);
	}
        else{
            qDebug() << "You didn't enter the right amount of letters!";
        }
    return 0;
}

void get_digits(double x){
    qDebug() << x;
    double digit_1 = x + 1;
    double digit_2 = x + .1;
    double digit_3 = x + 5;
    qDebug() << "digit_1: " << digit_1;
    qDebug() << "digit_2: " << digit_2;
    qDebug() << "digit_3: " << digit_3;
}
