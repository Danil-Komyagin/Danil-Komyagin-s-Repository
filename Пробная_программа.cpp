#include <iostream>
using namespace std;

void counter(float, float); // Cоздание прототипа функции, рассчитывающей средства

int main(){
    setlocale(LC_ALL, "RU");

    float CommonSumm, nalog;
    cout << "Введите количество Ваших средств, рассчитанных на месяц" << endl;
    cin >> CommonSumm;
    cout << "Введите сумму, необходимую для погашения налогов на текущий месяц" << endl;
    cin >> nalog;

    counter(CommonSumm, nalog);

    return 0;
}

void counter(float CommonSumm, float nalog) {

    float ost, rezerv, nepredv_traty, invest, bezop_rezerv, razvlec, products;

    cout << "Ваши средства на данный момент составляют " << CommonSumm << " RUB" << endl;
    cout << "Следующее распределение финансов будет наиболее подходящим для Вашего бюджета:" << endl;

    ost = CommonSumm - nalog;
    invest = 0.1 * ost;
    bezop_rezerv = 0.06 * ost;
    nepredv_traty = 0.09 * ost;
    razvlec = 0.27 * ost;
    products = 0.48 * ost;

    cout << " Средства для уплаты налогов "<< nalog <<" RUB" << endl;
    cout << " Средства для инвестиций "<< invest <<" RUB" << endl;
    cout << " Средства для 'подушки безопасности' "<< bezop_rezerv <<" RUB" << endl;
    cout << " Средства для непредвиденных трат "<< nepredv_traty <<" RUB" << endl;
    cout << " Средства для развлечений "<< razvlec <<" RUB" << endl;
    cout << " Средства для покупки продуктов "<< products <<" RUB" << endl;
}
