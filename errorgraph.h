#ifndef ERRORGRAPH_H
#define ERRORGRAPH_H

#include <QWidget>
#include "qcustomplot.h"
#include <QVector>

namespace Ui {
class ErrorGraph;
}

class ErrorGraph : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorGraph(QWidget *parent = nullptr);
    ~ErrorGraph();
    void plot_error(const QVector<double>& x,
                    const QVector<double>& e1,
                    const QVector<double>& e2);

private:
    Ui::ErrorGraph *ui;
};

#endif // ERRORGRAPH_H
