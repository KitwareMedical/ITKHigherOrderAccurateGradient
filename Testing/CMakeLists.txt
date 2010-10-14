set( INPUT_DIR ${ITK_NTH_ORDER_ACCURATE_GRADIENT_SOURCE_DIR}/Testing/Data/Input )

add_executable( itkNthOrderAccurateGradientImageFilterTest
  itkNthOrderAccurateGradientImageFilterTest.cxx
  )
target_link_libraries( itkNthOrderAccurateGradientImageFilterTest
  ITKCommon
  ITKIO
  )

# @todo compare components
add_test( itkNthOrderAccurateGradientImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkNthOrderAccurateGradientImageFilterTest
  itkNthOrderAccurateGradientImageFilterTest
  ${INPUT_DIR}/foot.mha
  itkNthOrderAccurateGradientImageFilterTest
  )


add_executable( itkNthOrderAccurateDerivativeImageFilterTest
  itkNthOrderAccurateDerivativeImageFilterTest.cxx
  )
target_link_libraries( itkNthOrderAccurateDerivativeImageFilterTest
  ITKCommon
  ITKIO
  )

# @todo compare output of regular with accuracy of 1
add_test( itkNthOrderAccurateDerivativeImageFilterTest
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/itkNthOrderAccurateDerivativeImageFilterTest
  itkNthOrderAccurateDerivativeImageFilterTest
  ${INPUT_DIR}/foot.mha
  itkNthOrderAccurateDerivativeImageFilterTest
  )
