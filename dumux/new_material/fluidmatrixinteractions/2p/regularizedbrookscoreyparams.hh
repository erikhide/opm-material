/*****************************************************************************
 *   Copyright (C) 2008 by Andreas Lauser, Bernd Flemisch                    *
 *   Institute of Hydraulic Engineering                                      *
 *   University of Stuttgart, Germany                                        *
 *   email: <givenname>.<name>@iws.uni-stuttgart.de                          *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version, as long as this copyright notice    *
 *   is included in its original form.                                       *
 *                                                                           *
 *   This program is distributed WITHOUT ANY WARRANTY.                       *
 *****************************************************************************/
/*!
 * \file
 *
 * \brief Specification of the params API for the Brooks-Corey
 *        capillary pressure model.
 */
#ifndef DUMUX_REGULARIZED_BROOKS_COREY_PARAMS_HH
#define DUMUX_REGULARIZED_BROOKS_COREY_PARAMS_HH

#include "brookscoreyparams.hh"

namespace Dumux
{
/*!
 * \brief A reference implementation of the params class for the
 *        regularized Brooks-Corey Sw-pC relation.
 */
template <class ScalarT>
class RegularizedBrooksCoreyParams : public Dune::BrooksCoreyParams<ScalarT>
{
    typedef Dune::BrooksCoreyParams<ScalarT> BrooksCoreyParams;

public:
    typedef ScalarT Scalar;

    RegularizedBrooksCoreyParams()
        : BrooksCoreyParams()
    {
    }
    
    RegularizedBrooksCoreyParams(Scalar pe, Scalar alpha)
        : BrooksCoreyParams(pe, alpha)
    {
    }

    /*!
     * \brief Threshold saturation below which the capillary pressure
     *        is regularized.
     *
     * This is just 5%. If you need a different value, overload this
     * class.
     */
    Scalar pCLowSw() const
    { return 0.05; }

    /*!
     * \brief Threshold saturation below which the relative
     *        permeability of the non-wetting phase gets regulatized.
     *
     * This is just 15%. If you need a different value, overload this
     * class.
     */
    Scalar krnLowSw() const
    { return 0.15; }

    /*!
     * \brief Threshold saturation above which the relative
     *        permeability of the wetting phase gets regulatized.
     *
     * This is just 85%. If you need a different value, overload this
     * class.
     */
    Scalar krwHighSw() const
    { return 0.85; }
};
}; // namespace Dumux

#endif
