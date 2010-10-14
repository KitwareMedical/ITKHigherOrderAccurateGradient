#ifndef __itkNthOrderAccurateGradientImageFilter_h
#define __itkNthOrderAccurateGradientImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"
#include "itkCovariantVector.h"

namespace itk {
/** \class NthOrderAccurateGradientImageFilter
 *
 * \brief Calculate the image gradient from a Nth order accurate
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
 * To specify the order of accuracy, use SetAccuracyOrder().
 *
 * \ingroup GradientFilters
 */
template< class TInputImage, class TOutputValueType = float > class ITK_EXPORT
  NthOrderAccurateGradientImageFilter: public ImageToImageFilter< TInputImage,
  Image< CovariantVector< TOutputValueType, ::itk::GetImageDimension<
                                       TInputImage >::ImageDimension >,
                                       ::itk::GetImageDimension< TInputImage
                                       >::ImageDimension > > { public:
  /** Extract dimension from input image. */
  itkStaticConstMacro(ImageDimension, unsigned int,
    TInputImage::ImageDimension);

  /** Standard class typedefs. */
  typedef NthOrderAccurateGradientImageFilter Self;

  /** Convenient typedefs for simplifying declarations. */
  typedef TInputImage                      InputImageType;
  typedef typename InputImageType::Pointer InputImagePointer;
  typedef Image< CovariantVector<
                   TOutputValueType, itkGetStaticConstMacro(OutputImageDimension) >,
                 itkGetStaticConstMacro(OutputImageDimension) >
  OutputImageType;
  typedef typename OutputImageType::Pointer OutputImagePointer;

  /** Standard class typedefs. */
  typedef ImageToImageFilter< InputImageType, OutputImageType > Superclass;
  typedef SmartPointer< Self >                                  Pointer;
  typedef SmartPointer< const Self >                            ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(NthOrderAccurateGradientImageFilter, ImageToImageFilter);

  /** Image typedef support. */
  typedef typename InputImageType::PixelType InputPixelType;
  typedef TOutputValueType                   OutputValueType;
  typedef CovariantVector<
    OutputValueType, itkGetStaticConstMacro(OutputImageDimension) >
  OutputPixelType;
  typedef typename OutputImageType::RegionType OutputImageRegionType;

#ifdef ITK_USE_CONCEPT_CHECKING
  /** Begin concept checking */
  itkConceptMacro( InputConvertibleToOutputCheck,
                  ( Concept::Convertible< InputPixelType, OutputValueType > ) );
  itkConceptMacro( OutputHasNumericTraitsCheck,
                  ( Concept::HasNumericTraits< OutputValueType > ) );
  /** End concept checking */
#endif

protected:
  NthOrderAccurateGradientImageFilter();
  virtual ~NthOrderAccurateGradientImageFilter() {}

private:
  NthOrderAccurateGradientImageFilter( const Self & ); // purposely not implemented
  void operator=( const Self & );                 // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkNthOrderAccurateGradientImageFilter.txx"
#endif

#endif
