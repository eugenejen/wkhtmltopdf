/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "WebKitDOMTestNode.h"

#include "DOMObjectCache.h"
#include "ExceptionCode.h"
#include "GObjectEventListener.h"
#include "JSMainThreadExecState.h"
#include "WebKitDOMBinding.h"
#include "WebKitDOMEventPrivate.h"
#include "WebKitDOMEventTarget.h"
#include "WebKitDOMTestNodePrivate.h"
#include "gobject/ConvertToUTF8String.h"
#include "webkitglobalsprivate.h"
#include <wtf/GetPtr.h>
#include <wtf/RefPtr.h>

namespace WebKit {

WebKitDOMTestNode* kit(WebCore::TestNode* obj)
{
    g_return_val_if_fail(obj, 0);

    if (gpointer ret = DOMObjectCache::get(obj))
        return static_cast<WebKitDOMTestNode*>(ret);

    return static_cast<WebKitDOMTestNode*>(DOMObjectCache::put(obj, WebKit::wrapTestNode(obj)));
}

WebCore::TestNode* core(WebKitDOMTestNode* request)
{
    g_return_val_if_fail(request, 0);

    WebCore::TestNode* coreObject = static_cast<WebCore::TestNode*>(WEBKIT_DOM_OBJECT(request)->coreObject);
    g_return_val_if_fail(coreObject, 0);

    return coreObject;
}

WebKitDOMTestNode* wrapTestNode(WebCore::TestNode* coreObject)
{
    g_return_val_if_fail(coreObject, 0);

    // We call ref() rather than using a C++ smart pointer because we can't store a C++ object
    // in a C-allocated GObject structure. See the finalize() code for the matching deref().
    coreObject->ref();

    return WEBKIT_DOM_TEST_NODE(g_object_new(WEBKIT_TYPE_DOM_TEST_NODE, "core-object", coreObject, NULL));
}

} // namespace WebKit

static void webkit_dom_test_node_dispatch_event(WebKitDOMEventTarget* target, WebKitDOMEvent* event, GError** error)
{
    WebCore::Event* coreEvent = WebKit::core(event);
    WebCore::TestNode* coreTarget = static_cast<WebCore::TestNode*>(WEBKIT_DOM_OBJECT(target)->coreObject);

    WebCore::ExceptionCode ec = 0;
    coreTarget->dispatchEvent(coreEvent, ec);
    if (ec) {
        WebCore::ExceptionCodeDescription description(ec);
        g_set_error_literal(error, g_quark_from_string("WEBKIT_DOM"), description.code, description.name);
    }
}

static gboolean webkit_dom_test_node_add_event_listener(WebKitDOMEventTarget* target, const char* eventName, GCallback handler, gboolean bubble, gpointer userData)
{
    WebCore::TestNode* coreTarget = static_cast<WebCore::TestNode*>(WEBKIT_DOM_OBJECT(target)->coreObject);
    return WebCore::GObjectEventListener::addEventListener(G_OBJECT(target), coreTarget, eventName, handler, bubble, userData);
}

static gboolean webkit_dom_test_node_remove_event_listener(WebKitDOMEventTarget* target, const char* eventName, GCallback handler, gboolean bubble)
{
    WebCore::TestNode* coreTarget = static_cast<WebCore::TestNode*>(WEBKIT_DOM_OBJECT(target)->coreObject);
    return WebCore::GObjectEventListener::removeEventListener(G_OBJECT(target), coreTarget, eventName, handler, bubble);
}

static void webkit_dom_event_target_init(WebKitDOMEventTargetIface* iface)
{
    iface->dispatch_event = webkit_dom_test_node_dispatch_event;
    iface->add_event_listener = webkit_dom_test_node_add_event_listener;
    iface->remove_event_listener = webkit_dom_test_node_remove_event_listener;
}

G_DEFINE_TYPE_WITH_CODE(WebKitDOMTestNode, webkit_dom_test_node, WEBKIT_TYPE_DOM_NODE, G_IMPLEMENT_INTERFACE(WEBKIT_TYPE_DOM_EVENT_TARGET, webkit_dom_event_target_init))

enum {
    PROP_0,
};

static void webkit_dom_test_node_finalize(GObject* object)
{

    WebKitDOMObject* domObject = WEBKIT_DOM_OBJECT(object);
    
    if (domObject->coreObject) {
        WebCore::TestNode* coreObject = static_cast<WebCore::TestNode*>(domObject->coreObject);

        WebKit::DOMObjectCache::forget(coreObject);
        coreObject->deref();

        domObject->coreObject = 0;
    }


    G_OBJECT_CLASS(webkit_dom_test_node_parent_class)->finalize(object);
}

static void webkit_dom_test_node_set_property(GObject* object, guint propertyId, const GValue* value, GParamSpec* pspec)
{
    WebCore::JSMainThreadNullState state;
    switch (propertyId) {
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, propertyId, pspec);
        break;
    }
}


static void webkit_dom_test_node_get_property(GObject* object, guint propertyId, GValue* value, GParamSpec* pspec)
{
    WebCore::JSMainThreadNullState state;
    switch (propertyId) {
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, propertyId, pspec);
        break;
    }
}


static void webkit_dom_test_node_constructed(GObject* object)
{

    if (G_OBJECT_CLASS(webkit_dom_test_node_parent_class)->constructed)
        G_OBJECT_CLASS(webkit_dom_test_node_parent_class)->constructed(object);
}

static void webkit_dom_test_node_class_init(WebKitDOMTestNodeClass* requestClass)
{
    GObjectClass* gobjectClass = G_OBJECT_CLASS(requestClass);
    gobjectClass->finalize = webkit_dom_test_node_finalize;
    gobjectClass->set_property = webkit_dom_test_node_set_property;
    gobjectClass->get_property = webkit_dom_test_node_get_property;
    gobjectClass->constructed = webkit_dom_test_node_constructed;



}

static void webkit_dom_test_node_init(WebKitDOMTestNode* request)
{
}

