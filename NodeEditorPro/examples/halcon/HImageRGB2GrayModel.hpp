﻿#pragma once

#include <iostream>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include "DataModelRegistry.hpp"
#include "NodeDataModel.hpp"
#include "halconcpp/HalconCpp.h"
#include "HImageData.hpp"
#include "HImageViewWidget.hpp"

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
class HImageRGB2GrayModel :public NodeDataModel
{
	Q_OBJECT
public:
	HImageRGB2GrayModel();
	virtual ~HImageRGB2GrayModel() {}

public:
	QString caption() const override
	{
		return QStringLiteral("图像转灰度");
	}
	QString name() const override
	{
		return QStringLiteral("图像转灰度");
	}
	virtual QString modelName() const
	{
		return QStringLiteral("图像转灰度");
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
		embeddedWidget() override { return Q_NULLPTR; }

	bool
		resizable() const override { return false; }
	NodeValidationState
		validationState() const override;
	QString
		validationMessage() const override;
protected:
	bool RunTask();

public:
	NodeValidationState modelValidationState = NodeValidationState::Warning;
	QString modelValidationError = QStringLiteral("图片输入未连接!");
private:
	std::shared_ptr<HImageData> m_hImage;

};
