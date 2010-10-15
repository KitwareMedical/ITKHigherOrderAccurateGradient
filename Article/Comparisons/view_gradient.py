#!/usr/bin/env python

import sys

import vtk

usage = sys.argv[0] + '  <original_image> <gradient_magnitude_image> <output_image>.png'

if len( sys.argv ) < 4:
    print( usage )
    sys.exit( 1 )

camera = vtk.vtkCamera()
camera.SetViewUp     (0.0, 1.0, 0.0)
camera.SetFocalPoint (127.5, 127.5, 0.0)
camera.SetPosition   (127.5, 127.5, 494.77095648274013)

original_reader = vtk.vtkMetaImageReader()
original_reader.SetFileName( sys.argv[1] )
original_reader.Update()

original_actor = vtk.vtkImageActor()
original_actor.SetInput( original_reader.GetOutput() )

original_ren = vtk.vtkRenderer()
original_ren.AddActor( original_actor )
original_ren.SetViewport( 0.0, 0.0, 0.5, 1.0 )
original_ren.SetActiveCamera( camera )

gradient_reader = vtk.vtkMetaImageReader()
gradient_reader.SetFileName( sys.argv[2] )
gradient_reader.Update()

min = 0.0
max = 90.0
shift = -1 * min
scale = 255./ ( max - min )

shift_scale = vtk.vtkImageShiftScale()
shift_scale.SetShift( shift )
shift_scale.SetScale( scale )
shift_scale.SetOutputScalarTypeToUnsignedChar()
shift_scale.SetInputConnection( gradient_reader.GetOutputPort() )

gradient_actor = vtk.vtkImageActor()
gradient_actor.SetInput( shift_scale.GetOutput() )

gradient_ren = vtk.vtkRenderer()
gradient_ren.AddActor( gradient_actor )
gradient_ren.SetViewport( 0.5, 0.0, 1.0, 1.0 )
gradient_ren.SetActiveCamera( camera )

ren_win = vtk.vtkRenderWindow()
ren_win.SetSize( 1200, 600 )
ren_win.AddRenderer( original_ren )
ren_win.AddRenderer( gradient_ren )

def ShowCameraPosition( obj, event ):
    ren_win = obj.GetRenderWindow()
    ren = ren_win.GetRenderers().GetFirstRenderer()
    cam = ren.GetActiveCamera()
    if( obj.GetKeySym() == 'space' ):
        print( '\ncamera.SetViewUp     ' + str( cam.GetViewUp() ) )
        print( 'camera.SetFocalPoint ' + str( cam.GetFocalPoint() ) )
        print( 'camera.SetPosition   ' + str( cam.GetPosition() ) )
iren = vtk.vtkRenderWindowInteractor()
iren.AddObserver("KeyPressEvent", ShowCameraPosition)
iren_style = vtk.vtkInteractorStyleImage()
iren.SetInteractorStyle( iren_style )
iren.SetRenderWindow( ren_win )

ren_win.Render()
w2if = vtk.vtkWindowToImageFilter()
w2if.SetInput( ren_win )
w2if.Update()

writer = vtk.vtkPNGWriter()
writer.SetFileName( sys.argv[3] )
writer.SetInput( w2if.GetOutput() )
writer.Write()

iren.Initialize()
ren_win.Render()
iren.Start()
