// Copyright (c) 2019 The CATSCOIN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RECEIVEWIDGET_H
#define RECEIVEWIDGET_H

#include "qt/catscoin/pwidget.h"
#include "addresstablemodel.h"
#include "qt/catscoin/furabstractlistitemdelegate.h"
#include "qt/catscoin/addressfilterproxymodel.h"

#include <QSpacerItem>
#include <QWidget>
#include <QPixmap>

class CATSCOINGUI;
class SendCoinsRecipient;

namespace Ui {
class ReceiveWidget;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class ReceiveWidget : public PWidget
{
    Q_OBJECT

public:
    explicit ReceiveWidget(CATSCOINGUI* parent);
    ~ReceiveWidget();

    void loadWalletModel() override;

public slots:
    void onRequestClicked();
    void onMyAddressesClicked();
    void onNewAddressClicked();

private slots:
    void changeTheme(bool isLightTheme, QString &theme) override ;
    void onLabelClicked();
    void onCopyClicked();
    void refreshView(QString refreshAddress = QString());
    void handleAddressClicked(const QModelIndex &index);
private:
    Ui::ReceiveWidget *ui;

    FurAbstractListItemDelegate *delegate;
    AddressTableModel* addressTableModel = nullptr;
    AddressFilterProxyModel *filter = nullptr;

    QSpacerItem *spacer = nullptr;

    // Cached last address
    SendCoinsRecipient *info = nullptr;
    // Cached qr
    QPixmap *qrImage = nullptr;

    void updateQr(QString address);
    void updateLabel();
    void showAddressGenerationDialog(bool isPaymentRequest);

    bool isShowingDialog = false;

};

#endif // RECEIVEWIDGET_H
