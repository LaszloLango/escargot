#include "Escargot.h"
#include "GlobalObject.h"
#include "Context.h"
#include "BooleanObject.h"

namespace Escargot {

static Value builtinBooleanConstructor(ExecutionState& state, Value thisValue, size_t argc, Value* argv, bool isNewExpression)
{
    BooleanObject* boolObj;
    bool primitiveVal = (argv[0].isUndefined()) ? false : argv[0].toBoolean(state);
    if (isNewExpression && thisValue.isObject() && thisValue.asObject()->isBooleanObject()) {
        boolObj = thisValue.asPointerValue()->asObject()->asBooleanObject();
        boolObj->setPrimitiveValue(state, primitiveVal);
        return boolObj;
    } else
        return Value(primitiveVal);
}

void GlobalObject::installBoolean(ExecutionState& state)
{
    m_boolean = new FunctionObject(state, NativeFunctionInfo(state.context()->staticStrings().Boolean, builtinBooleanConstructor, 1, [](ExecutionState& state, size_t argc, Value* argv) -> Object* {
                                       return new BooleanObject(state);
                                   }),
                                   FunctionObject::__ForBuiltin__);
    m_boolean->markThisObjectDontNeedStructureTransitionTable(state);
    m_boolean->setPrototype(state, m_functionPrototype);
    m_booleanPrototype = m_objectPrototype;
    m_booleanPrototype = new BooleanObject(state, false);
    m_booleanPrototype->setPrototype(state, m_objectPrototype);

    m_boolean->setFunctionPrototype(state, m_booleanPrototype);

    defineOwnProperty(state, ObjectPropertyName(state.context()->staticStrings().Boolean),
                      ObjectPropertyDescriptor(m_boolean, (ObjectPropertyDescriptor::PresentAttribute)(ObjectPropertyDescriptor::WritablePresent | ObjectPropertyDescriptor::ConfigurablePresent)));
}
}
