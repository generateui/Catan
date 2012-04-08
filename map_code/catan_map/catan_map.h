#ifndef CATAN_MAP_H
#define CATAN_MAP_H

#include <QMainWindow>

namespace Ui {
    class catan_map;
}

class catan_map : public QMainWindow
{
    Q_OBJECT

public:
    explicit catan_map(QWidget *parent = 0);
    ~catan_map();

private:
    Ui::catan_map *ui;
};

#endif // CATAN_MAP_H
