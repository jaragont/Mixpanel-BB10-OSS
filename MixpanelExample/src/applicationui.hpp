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

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include "MixpanelMessageQueue.hpp"
#include "MixpanelEvent.hpp"
#include "MixpanelPeople.hpp"

class Mixpanel;

namespace bb
{
    namespace cascades
    {
        class LocaleHandler;
    }
}

class QTranslator;

/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI();
    virtual ~ApplicationUI() {}
    Q_INVOKABLE  void sendProfileUpdate();
    Q_INVOKABLE  void sendCoinsIncrement();
    Q_INVOKABLE  void updateSuperProperties();
    Q_INVOKABLE  void flushMixpanelMessages();
    Q_INVOKABLE  void forceTrackEventError();
    Q_INVOKABLE  void forceEngageProfileError();

private slots:
    void mixpanelMessagePosted(const MixpanelMessageQueue::MixpanelPostMessageError errorCode, const QVariantMap analyticMessage);
    void mixpanelTrackError(MixpanelEvent::TrackEventError error, const QString eventName);
    void mixpanelEngageProfileError(const MixpanelPeople::EngageProfileError errorId, const QString action, const QVariantMap properties);
    void onSystemLanguageChanged();
private:
    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler* m_pLocaleHandler;
    Mixpanel* m_mixpanel;
};

#endif /* ApplicationUI_HPP_ */