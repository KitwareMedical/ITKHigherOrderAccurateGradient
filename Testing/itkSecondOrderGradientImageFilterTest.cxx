#include "itkTestMain.h"

void RegisterTests()
{
  REGISTER_TEST(itkSecondOrderGradientImageFilterTest);
}

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "itkSecondOrderGradientImageFilter.h"

int itkSecondOrderGradientImageFilterTest(int argc, char *argv[])
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
  typedef itk::Image< PixelType, Dimension > InputImageType;

  typedef itk::ImageFileReader< InputImageType > ReaderType;
  ReaderType::Pointer reader = ReaderType::New();

  return EXIT_SUCCESS;
}
