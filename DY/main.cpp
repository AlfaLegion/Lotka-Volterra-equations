#include "dy.h"
#include <QtWidgets/QApplication>
#include"qcustomplot.h"
double f1(double x, double y)
{
	double k11 = 0.09;
	double k12 = 0.004;
	return k11*x - k12*x*y;
}
double f2(double x, double y)
{
	double k21 = 0.03;
	double k22 = 0.001;
	return -k21*y + k22*x*y;
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QCustomPlot customPlot;
	QVector<double>y_vec,x_vec,t_vec;
	double xi = 100;// жертвы
	double yi = 20;// хищники
	double h = 0.01;
	for (double t = 0; t < 1000; t += h)
	{
		double k1 = h*f1(xi, yi);
		double m1 = h*f2(xi, yi);
		double k2 = h*f1(xi + k1 / 2.0, yi + m1 / 2.0);
		double m2 = h*f2(xi + k1 / 2.0, yi + m1 / 2.0);
		double k3 = h*f1(xi + k2 / 2.0, yi + m2 / 2.0);
		double m3 = h*f2(xi + k2 / 2.0, yi + m2 / 2.0);
		double k4 = h*f1(xi + k3, yi + m3);
		double m4 = h*f2(xi + k3, yi + m3);

		xi = xi + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
		yi = yi + (m1 + 2 * m2 + 2 * m3 + m4) / 6.0;
		x_vec.push_back(xi);
		y_vec.push_back(yi);
		t_vec.push_back(t);
	}
	customPlot.addGraph();
	customPlot.graph(0)->setData(t_vec,x_vec);
	customPlot.addGraph();
	// зависимость количетсва хищников от времени
	customPlot.graph(1)->setPen(QPen(Qt::red));
	customPlot.graph(1)->setData(t_vec, y_vec);
	customPlot.xAxis->setRange(0, 200);
	customPlot.yAxis->setRange(0, 200);	
	customPlot.replot();
	customPlot.setWindowTitle("DY");
	customPlot.resize(600, 500);
	customPlot.show();
	return a.exec();
}
