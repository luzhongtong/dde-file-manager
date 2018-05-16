/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     Gary Wang <wzc782970009@gmail.com>
 *
 * Maintainer: Gary Wang <wangzichong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "dfmnetworkcrumbcontroller.h"

#include "dfmcrumbitem.h"

#include "pathmanager.h"

#include "singleton.h"

DFM_BEGIN_NAMESPACE

DFMNetworkCrumbController::DFMNetworkCrumbController(QObject *parent)
    : DFMCrumbInterface(parent)
{

}

DFMNetworkCrumbController::~DFMNetworkCrumbController()
{

}

bool DFMNetworkCrumbController::supportedUrl(DUrl url)
{
    return (url.scheme() == NETWORK_SCHEME);
}

QList<CrumbData> DFMNetworkCrumbController::seprateUrl(const DUrl &url)
{
    Q_UNUSED(url);
    QString displayText = Singleton<PathManager>::instance()->getSystemPathDisplayName("Network");
    return { CrumbData(DUrl(NETWORK_ROOT), displayText, "CrumbIconButton.Network") };
}

DFMCrumbItem *DFMNetworkCrumbController::createCrumbItem(const CrumbData &data)
{
    return new DFMCrumbItem(data);
}

QStringList DFMNetworkCrumbController::getSuggestList(const QString &text)
{

}

DFM_END_NAMESPACE