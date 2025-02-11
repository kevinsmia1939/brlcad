/*
 * Poly2Tri Copyright (c) 2009-2010, Poly2Tri Contributors
 * http://code.google.com/p/poly2tri/
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * * Neither the name of Poly2Tri nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without specific
 *   prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "cdt.h"

namespace p2t {

    CDT::CDT()
    {
	sweep_context_ = new SweepContext();
	sweep_ = new Sweep;
    }

    CDT::CDT(std::vector<Point*> &polyline)
    {
	sweep_context_ = new SweepContext(polyline);
	sweep_ = new Sweep;
    }

    void CDT::AddOuterLoop(std::vector<Point*> &polyline)
    {
	sweep_context_->AddOuterLoop(polyline);
    }
    void CDT::AddHole(std::vector<Point*> &polyline)
    {
	sweep_context_->AddHole(polyline);
    }

    void CDT::AddPoint(Point* point) {
	sweep_context_->AddPoint(point);
    }

    std::vector<Point*>& CDT::GetPoints() {
	return sweep_context_->GetPoints();
    }

    void CDT::Triangulate(bool finalize, int num_points)
    {
	sweep_->Triangulate(*sweep_context_, finalize, num_points);
    }

    std::vector<p2t::Triangle*>& CDT::GetTriangles()
    {
	return sweep_context_->GetTriangles();
    }

    std::list<p2t::Triangle*>& CDT::GetMap()
    {
	return sweep_context_->GetMap();
    }

    CDT::~CDT()
    {
	delete sweep_context_;
	delete sweep_;
    }

}


// Local Variables:
// tab-width: 8
// mode: C++
// c-basic-offset: 4
// indent-tabs-mode: t
// c-file-style: "stroustrup"
// End:
// ex: shiftwidth=4 tabstop=8

