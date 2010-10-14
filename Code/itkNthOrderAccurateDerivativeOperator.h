/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkNthOrderAccurateDerivativeOperator.h
  Language:  C++

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkNthOrderAccurateDerivativeOperator_h
#define __itkNthOrderAccurateDerivativeOperator_h

#include "itkNeighborhoodOperator.h"

namespace itk
{
/**
 * \class NthOrderAccurateDerivativeOperator
 * \brief A NeighborhoodOperator for calculating an n-th order accurate derivative
 * at a pixel.
 *
 * \brief Calculate the image derivative from a Nth order accurate
 * central-difference derivative kernel.
 *
 * Based on the work here:
 *
 * Khan, IR and Ohba, Ryoji.  "Closed-form expressions for the finite difference
 * approximations of first and higher derivatives based on Taylor series."
 * Journal of Computational and Applied Mathematics.  vol 107.  p. 179-193.
 * 1999.
 *
 * Khan, IR and Ohba, Ryoji.  "Taylor series based finite difference
 * approximations of higher-degree derivatives."  Journal of Computational and
 * Applied Mathematics.  vol 154.  p. 115-124.  2003.
 *
 * To specify the order of accuracy, use SetOrderOfAccuracy().
 *
 * @todo: implement support for higher order derivatives.
 *
 * \sa DerivativeOperator
 * \sa NeighborhoodOperator
 * \sa Neighborhood
 * \sa ForwardDifferenceOperator
 * \sa BackwardDifferenceOperator
 *
 * \ingroup Operators
 */
template< class TPixel, unsigned int VDimension = 2,
          class TAllocator = NeighborhoodAllocator< TPixel > >
class ITK_EXPORT NthOrderAccurateDerivativeOperator:
  public NeighborhoodOperator< TPixel, VDimension, TAllocator >
{
public:
  /** Standard class typedefs. */
  typedef NthOrderAccurateDerivativeOperator Self;
  typedef NeighborhoodOperator<
    TPixel, VDimension, TAllocator >           Superclass;

  typedef typename Superclass::PixelType     PixelType;
  typedef typename Superclass::PixelRealType PixelRealType;

  /** Run-time type information (and related methods). */
  itkTypeMacro(NthOrderAccurateDerivativeOperator, NeighborhoodOperator);

  /** Constructor. */
  NthOrderAccurateDerivativeOperator():
    m_Order(1),
    m_OrderOfAccuracy(1)
  {}

  /** Copy constructor. */
  NthOrderAccurateDerivativeOperator(const Self & other):
    NeighborhoodOperator< TPixel, VDimension, TAllocator >(other)
  { m_Order = other.m_Order;  }

  /** Assignment operator */
  Self & operator=(const Self & other)
  {
    Superclass::operator=(other);
    m_Order = other.m_Order;
    return *this;
  }

  /** Sets the order of the derivative. */
  void SetOrder(const unsigned int & order)
  {
    this->m_Order = order;
  }

  /** Returns the order of the derivative. */
  unsigned int GetOrder() const { return m_Order; }

  /** Sets the order of accuracy of the derivative. The derivative estimate will
   * be accurate out to the given order in terms of Taylor Series terms.  The
   * radius of the neighborhood operator is also equal to the given order.  */
  void SetOrderOfAccuracy(const unsigned int & order)
  {
    this->m_OrderOfAccuracy = order;
  }

  unsigned int GetOrderOfAccuracy() const { return m_OrderOfAccuracy; }

  /** Prints some debugging information */
  virtual void PrintSelf(std::ostream & os, Indent i) const
  {
    os << i << "NthOrderAccurateDerivativeOperator { this=" << this
       << ", m_Order = " << m_Order
       << ", m_OrderOfAccuracy = " << m_OrderOfAccuracy << "}" << std::endl;
    Superclass::PrintSelf( os, i.GetNextIndent() );
  }

protected:
  /** Typedef support for coefficient vector type.  Necessary to
   * work around compiler bug on VC++. */
  typedef typename Superclass::CoefficientVector CoefficientVector;

  /** Calculates operator coefficients. */
  CoefficientVector GenerateCoefficients();

  /** Arranges coefficients spatially in the memory buffer. */
  void Fill(const CoefficientVector & coeff)
  {   Superclass::FillCenteredDirectional(coeff);  }
private:
  CoefficientVector GenerateFirstOrderCoefficients();

  /** Order of the derivative. */
  unsigned int m_Order;

  /** Order of accuracy. */
  unsigned int m_OrderOfAccuracy;
};
} // namespace itk

#if ITK_TEMPLATE_TXX
#include "itkNthOrderAccurateDerivativeOperator.txx"
#endif

#endif
