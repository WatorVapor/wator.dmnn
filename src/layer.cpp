/*
Copyright (c) 2015, Wator Vapor
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of wator nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include "wator.hpp"
using namespace Wator;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace boost::property_tree;

/**
 * Constructor
 **/
LayerBase::LayerBase()
{
}

/**
 * Constructor
 * @param [in] info layer parameter.
 **/
LayerBase::LayerBase(const ptree& info)
{
}


/**
 * bottom
 * @param [in] lyr layer.
 * @return None.
 **/
void LayerBase::bottom(LayerBasePtr lyr)
{
    this->bottom_.push_back(lyr);
}

/**
 * top
 * @param [in] lyr layer.
 * @return None.
 **/
void LayerBase::top(LayerBasePtr lyr)
{
    this->top_.push_back(lyr);
}


/**
 * round
 * @return None.
 **/
void LayerBase::round(void)
{
    TRACE_VAR(top_.size());
    for(auto & top:top_){
        top->round();
    }
}

/**
 * forward
 * @return None.
 **/
void LayerBase::forward(void)
{
}


/**
 * Constructor
 **/
LayerInput::LayerInput()
{
}
LayerInput::~LayerInput()
{
    blobs_.clear();
}



/**
 * Constructor
 * @param [in] info layer parameter.
 **/
LayerInput::LayerInput(const ptree& info)
{
}


/**
 * load
 * @return None.
 **/
void LayerInput::load(bool train)
{
}


/**
 * get ptr
 * @return None.
 **/
shared_ptr<Blob<uint8_t>> LayerInput::getBlob(const LayerBase *who)
{
    int i = 0;
    TRACE_VAR(top_.size());
    for(auto top:top_)
    {
        if(who == top.get())
        {
            TRACE_VAR(blobs_.size());
            if(blobs_.size() > i)
            {
                return blobs_[i];
            }
            else
            {
                FATAL_VAR("fatal errro");
            }
        }
        i++;
    }
    return nullptr;
}


/**
 * Constructor
 **/
LayerHidden::LayerHidden()
:memory_(new ImplicitMemory)
{
}

LayerHidden::~LayerHidden()
{
    INFO_VAR(this);
    pinchs_.clear();
    blobs_.clear();
}


/**
 * Constructor
 * @param [in] info layer parameter.
 **/
LayerHidden::LayerHidden(const ptree& info)
{
}


//vector<map<uint64_t,uint64_t>> LayerHidden::memory_({{}});

/**
 * Constructor
 **/
LayerOutput::LayerOutput()
{
}

/**
 * Constructor
 * @param [in] info layer parameter.
 **/
LayerOutput::LayerOutput(const ptree& info)
{
}

