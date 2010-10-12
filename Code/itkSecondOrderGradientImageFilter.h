#ifndef __itkSecondOrderGradientImageFilter_h
#define __itkSecondOrderGradientImageFilter_h

#include "itkImageToImageFilter.h"
#include "itkImage.h"
#include "itkCovariantVector.h"

namespace itk
{
/** \class SecondOrderGradientImageFilter
 *
 * \brief Calculate the image gradient from a second order accurate gradient
 * kernel.
 *
 * \ingroup GradientFilters
 */
template< class TInputImage, class TOutputValueType = float >
class ITK_EXPORT SecondOrderGradientImageFilter:
  public ImageToImageFilter< TInputImage,
                             Image< CovariantVector< TOutputValueType,
                                                     ::itk::GetImageDimension< TInputImage >::ImageDimension >,
                                    ::itk::GetImageDimension< TInputImage >::ImageDimension > >
{
public:
  /** Extract dimension from input image. */
  itkStaticConstMacro(ImageDimension, unsigned int,
                      TInputImage::ImageDimension);

  /** Standard class typedefs. */
  typedef SecondOrderGradientImageFilter Self;

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
  itkTypeMacro(SecondOrderGradientImageFilter, ImageToImageFilter);

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
  SecondOrderGradientImageFilter();
  virtual ~SecondOrderGradientImageFilter() {}

private:
  SecondOrderGradientImageFilter( const Self & ); // purposely not implemented
  void operator=( const Self & );                 // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkSecondOrderGradientImageFilter.txx"
#endif

#endif
