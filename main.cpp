#include <QApplication>
#include <QGraphicsView>

#include "game.h"
#include "utility.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QGraphicsView graphicsView;
	graphicsView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	graphicsView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	graphicsView.setFixedSize(Screen::Width, Screen::Height);

	QGraphicsScene scene;
	scene.setSceneRect(graphicsView.geometry().x(), graphicsView.geometry().y(),
					   graphicsView.geometry().width(), graphicsView.geometry().height());
	graphicsView.setScene(&scene);

	graphicsView.show();

	Game game(scene);
	a.installEventFilter(&game);
	return a.exec();
}
