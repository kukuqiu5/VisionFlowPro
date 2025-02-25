﻿#pragma once

#include <iostream>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "DataModelRegistry.hpp"
#include "NodeDataModel.hpp"
#include "halconcpp/HalconCpp.h"
#include "HImageData.hpp"
#include "HImageViewWidget.hpp"
#include "DrawShapeView.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;
using namespace HalconCpp;
/**
 * \brief halcon 图像rgb2gray节点
 */
class HImageReduceDomainModel :public NodeDataModel
{
	Q_OBJECT
public:
	HImageReduceDomainModel();
	virtual ~HImageReduceDomainModel() {}

public:
	QString caption() const override
	{
		return QStringLiteral("选区掩膜");
	}
	QString name() const override
	{
		return QStringLiteral("选区掩膜");
	}
	virtual QString modelName() const
	{
		return QStringLiteral("选区掩膜");
	}
	unsigned int
		nPorts(PortType portType) const override;

	NodeDataType
		dataType(PortType portType, PortIndex portIndex) const override;

	std::shared_ptr<NodeData>
		outData(PortIndex port) override;

	void
		setInData(std::shared_ptr<NodeData>, int) override;

	QWidget*
		embeddedWidget() override { return btn_drawReg; }

	bool
		resizable() const override { return false; }
	NodeValidationState
		validationState() const override;
	QString
		validationMessage() const override;
	QJsonObject save() const override;
	void restore(QJsonObject const&) override;
protected:
	bool RunTask();

public slots:
	void OnNewRegionData(ShapeDataStruct _data);
public:
	NodeValidationState modelValidationState = NodeValidationState::Warning;
	QString modelValidationError = QStringLiteral("图片输入未连接!");
private:
	//HWindow* h_window;
	QPushButton* btn_drawReg;
	HRegion m_domain;
	std::shared_ptr<ShapeDataStruct> m_region_data;
	std::shared_ptr<HImageData> m_hImage;
	std::shared_ptr<HImageData> m_result;
};
