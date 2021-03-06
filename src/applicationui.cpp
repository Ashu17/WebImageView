/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/*
 *
 * This project is a combination of two different projects into one and some small modifications
 * 1- RileyGB WebImageView ( https://github.com/RileyGB/BlackBerry10-Samples/tree/master/WebImageViewSample )
 * 2- ealejandr0 WebImageView ( https://github.com/ealejandr0/WebImageView )
 *
 */


#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include "src/WebImageView/WebImageView.h"

using namespace bb::cascades;

ApplicationUI::ApplicationUI() :
        QObject()
{
    qmlRegisterType<WebImageView>("WebImageView", 1, 0, "WebImageView");

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    // Set created root object as the application scene
    Application::instance()->setScene(root);
}
