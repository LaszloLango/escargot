/*
 * Copyright (c) 2016-present Samsung Electronics Co., Ltd
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 *  USA
 */

#ifndef RestElementNode_h
#define RestElementNode_h

#include "IdentifierNode.h"
#include "Node.h"

namespace Escargot {

class RestElementNode : public Node {
public:
    RestElementNode(IdentifierNode* argument)
        : Node()
    {
        m_argument = argument;
    }

    virtual ~RestElementNode()
    {
    }

    virtual ASTNodeType type() { return ASTNodeType::RestElement; }
    IdentifierNode* argument()
    {
        return m_argument.get();
    }

protected:
    RefPtr<IdentifierNode> m_argument;
};
}

#endif
