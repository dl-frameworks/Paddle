// Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "paddle/fluid/framework/ir/graph.h"
#include "paddle/fluid/framework/ir/pass.h"
#include "paddle/fluid/framework/scope.h"

namespace paddle {
namespace framework {
namespace ir {

static const char kParamScopeAttr[] = "param_scope";

class FusePassBase : public Pass {
 public:
  void Init(Graph* graph) const { graph_ = graph; }

  Scope* param_scope() const {
    PADDLE_ENFORCE(graph_->Has(kParamScopeAttr));
    return graph_->Get<framework::Scope*>(kParamScopeAttr);
  }

  virtual ~FusePassBase() {}

 protected:
  mutable Graph* graph_;
};

}  // namespace ir
}  // namespace framework
}  // namespace paddle