#include "itkTestMain.h"

void RegisterTests()
{
  REGISTER_TEST(itkNthOrderAccurateGradientImageFilterTest);
}

#include "itkGradientToMagnitudeImageFilter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "itkNthOrderAccurateGradientImageFilter.h"

int itkNthOrderAccurateGradientImageFilterTest(int argc, char *argv[])
{
  if ( argc < 3 )
    {
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputDisplacementImage outputPrefix ";
    std::cerr << std::endl;
    return EXIT_FAILURE;
    }

  const unsigned int Dimension = 2;
  typedef float                              PixelType;
  typedef itk::Image< PixelType, Dimension > ImageType;

  typedef itk::ImageFileReader< ImageType > ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( argv[1] );

  typedef itk::NthOrderAccurateGradientImageFilter< ImageType, float > FilterType;
  typedef FilterType::OutputImageType GradientImageType;
  FilterType::Pointer filter = FilterType::New();
  filter->SetInput( reader->GetOutput() );

  typedef itk::ImageFileWriter< GradientImageType > GradientWriterType;
  GradientWriterType::Pointer gradientWriter = GradientWriterType::New();
  gradientWriter->SetInput( filter->GetOutput() );
  std::string outputPrefix = argv[2];
  gradientWriter->SetFileName( outputPrefix + "_Gradient.mha" );

  try
    {
    gradientWriter->Update();
    }
  catch (itk::ExceptionObject& ex)
    {
    std::cerr << "Exception caught!" << std::endl;
    std::cerr << ex << std::endl;
    return EXIT_FAILURE;
    }

  typedef itk::GradientToMagnitudeImageFilter< GradientImageType, ImageType >
    GradientMagnitudeFilterType;
  GradientMagnitudeFilterType::Pointer gradientMagnitude = GradientMagnitudeFilterType::New();
  gradientMagnitude->SetInput( filter->GetOutput() );

  typedef itk::ImageFileWriter< ImageType > GradientMagnitudeWriterType;
  GradientMagnitudeWriterType::Pointer gradientMagnitudeWriter = GradientMagnitudeWriterType::New();
  gradientMagnitudeWriter->SetInput( gradientMagnitude->GetOutput() );
  gradientMagnitudeWriter->SetFileName( outputPrefix + "_GradientMagnitude.mha" );

  try
    {
    gradientMagnitudeWriter->Update();
    }
  catch (itk::ExceptionObject& ex)
    {
    std::cerr << "Exception caught!" << std::endl;
    std::cerr << ex << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
