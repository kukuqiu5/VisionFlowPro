﻿#pragma once

#include <iostream>

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "DataModelRegistry.hpp"
#include "NodeDataModel.hpp"

using QtNodes::PortType;
using QtNodes::PortIndex;
using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDataModel;
using QtNodes::NodeValidationState;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class ImageShowModel : public NodeDataModel
{
	Q_OBJECT

public:
	ImageShowModel();

	virtual
		~ImageShowModel() {}

public:

	QString
		caption() const override
	{
		return QStringLiteral("QPixmap 显示");
	}

	QString
		name() const override
	{
		return QStringLiteral("QPixmap显示节点");
	}

public:

	virtual QString
		modelName() const
	{
		return QStringLiteral("QPixmap显示");
	}

	unsigned int
		nPorts(PortType portType) const override;

	NodeDataType
		dataType(PortType portType, PortIndex portIndex) const override;

	std::shared_ptr<NodeData>
		outData(PortIndex port) override;

	void
		setInData(std::shared_ptr<NodeData> nodeData, PortIndex port) override;

	QWidget*
		embeddedWidget() override { return _label; }

	bool
		resizable() const override { return true; }

protected:

	bool
		eventFilter(QObject* object, QEvent* event) override;

private:

	QLabel* _label;

	std::shared_ptr<NodeData> _nodeData;
};
