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
