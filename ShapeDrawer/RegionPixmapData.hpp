﻿#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsObject>

class RegionPixmapData
{
public:
	int width = 512;
	int height = 512;
	double w_ratio = 1.0;
	double h_ratio = 1.0;
	//绘制
	QVector<QPolygonF> comformPolygon;
	QVector<int> comformOp;
public:
	RegionPixmapData()
	{
		width = 512;
		height = 512;
	}
	~RegionPixmapData()
	{

	}
};
