#include "errorgraph.h"
#include "ui_errorgraph.h"

ErrorGraph::ErrorGraph(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ErrorGraph)
{
    ui->setupUi(this);
}

ErrorGraph::~ErrorGraph()
{
    delete ui;
}

void ErrorGraph::plot_error(const QVector<double>& x,
                            const QVector<double>& e1,
                            const QVector<double>& e2){
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(*x.begin(), *(--x.end()));
    ui->widget->yAxis->setRange(-1.0,1.0);

    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->graph(0)->addData(x,e1);
    ui->widget->graph(1)->addData(x,e2);

    double xScaleFactor = 10.0; // Сжать по X
    double yScaleFactor = 0.005; // Растянуть по Y

    // Масштабирование осей
    ui->widget->xAxis->scaleRange(xScaleFactor, ui->widget->xAxis->range().center());
    ui->widget->yAxis->scaleRange(yScaleFactor, ui->widget->yAxis->range().center());
    ui->widget->replot();

    ui->widget->setInteraction(QCP::iRangeZoom,true);
    ui->widget->setInteraction(QCP::iRangeDrag,true);
}
