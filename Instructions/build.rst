:Authors:
    BoB LeSuer

:Version: 0.1-231004
:File: build.rst


Building the chassis
====================

Purpose
-------

How to put together the chassis of your 3D printed vehicle.


Related Topics
--------------

* TBD

Procedure
---------

Part 0 - getting started
^^^^^^^^^^^^^^^^^^^^^^^^

.. list-table:: Part 0 - Organize and prepare materials.
    :widths: 5 25 50
    :header-rows: 0
    :align: center

    * - 1 
      - All of the items you should have for the build.
      - .. image:: media/build_plate.jpg
            :width: 200 px
    * - 2
      - A complete BOM will come soon.
      - .. image:: media/missing.jpg
            :width: 200 px
    * - 3
      - Additional tools include a small (M2) allen key, craft knife and clippers
      - .. image:: media/additional_tools.jpg
            :width: 200 px
    * - 4
      - Each of the wheels was printed with a bit of material  in the center that must be removed with a craft knife.
      - .. image:: media/wheel_cleaning.jpg
          :width: 200 px
    * - 5
      - The base has two support beams that should be removed.
      - .. image:: media/base_plate_clips.jpg
          :width: 200 px
    * - 6
      - The steering frame has two support beams that should be removed.
      - .. image:: media/steering_frame_clips.jpg
          :width: 200 px


Drive assembly
^^^^^^^^^^^^^^
.. list-table:: Part 1 - Prepare the base and assemble the drive.
    :widths: 5 25 50
    :header-rows: 0
    :align: center

    * - 1 
      - The power switch can be pushed from the outside into one of the holes in the base. It should fit snugly, but you may use an M2 bolt and nut to secure the switch in place.
      - .. image:: media/switcha.jpg
          :width: 200 px
    * - 2
      - The nuts will not go flush against the plastic.
      - .. image:: media/switchb.jpg
          :width: 200 px
    * - 3
      - Obtain the DC motor, motor frames, thin gears, and some bolts (2x M3-8, 1x M3-20, 2x M3-25)
      - .. image:: media/drive_parts.jpg
          :width: 200 px
    * - 4
      - Sandwich the motor between the two frame pieces. Note that one of the pieces has room for the countersunk bolts. Secure the back of the motor with the M3-20 bolt and the front of the motor with the M3-25 bolts. The plastic is self threading and does not need a nut. 
      - .. image:: media/framed_motor.jpg
          :width: 200 px
    * - 5
      - Align the gears onto the white shaft posts of the motor. Use the M3-8 bolts to secure the gears to the shaft. These bolts will not screw entirely into the hole.
      - .. image:: media/drive_gears.jpg
          :width: 200 px

The drive is now complete and can be set aside until later in the build.

Steering Assembly
^^^^^^^^^^^^^^^^^
.. list-table:: Part 3 - Assemble the steering mechanism
    :widths: 5 25 50
    :header-rows: 0
    :align: center

    * - 1
      - Obtain the steering bar, steering arm, the two wheel blocks, the steering frame, and some bolts (2 each of  M3-8, M3-12 and M3-14)
      - .. image:: media/steering_parts.jpg
          :width: 200 px
    * - 2
      - Connect the two wheel blocks to the steering bar using the M3-12 bolts. Note that the wheel blocks are symmetric and do not have an *up*. The steering bar does have one side to support the countersunk bolts. 
      - .. image:: media/steering_1.jpg
          :width: 200 px
    * - 3
      - Turn over the steering bar and attach the steering arm using one of the M3-8 bolts. The arm has one side to support the countersunk bolts. Note that in this picture, the steering frame supports have not been clipped. If you haven't done this, do it now.
      - .. image:: media/steering_2.jpg
          :width: 200 px
    * - 4
      - Connect the bar/arm assembly to the frame using the remaining M3-8 bolt. Adjust the tightness of both M3-8 bolts so that the assembly moves freely but is not wobbly.
      - .. image:: media/steering_3.jpg
          :width: 200 px
    * - 5
      - Lastly, connect the wheel blocks to the steering frame with the M3-14 bolts.
      - .. image:: media/steering_4.jpg
          :width: 200 px

The steering assembly is now complete and can be set aside until later in the build.

Servo assembly
^^^^^^^^^^^^^^
.. list-table:: Part 4 - Install the servo and steering assembly.
    :widths: 5 25 50
    :header-rows: 0
    :align: center

    * - 1
      - Obtain the base plate and 3D printed servo arm adapter. You'll also need the servo, the arm that fits into the adapter, and the three screws that come with the servo.
      - .. image:: media/servo_assembly.jpg
            :width: 200 px
    * - 2
      - Insert the servo arm into the adapter. The mount point for the servo arm should be pointing awa from the adapter. Depending on the print, you may need some glue or tape to secure the arm to the adapter. Screw a M3-8 bolt into the hole on the 3D printed servo arm adapter. 
      - .. image:: media/servo_arm.jpg
            :width: 200 px
    * - 3
      - Attach the servo arm to the servo. The motor can only swing a bit over 180 degrees. Using the servo arm as a guide, manually adjust the servo so that it is half way through the entire range of rotation. If necessary, reposition the servo arm so that it is facing 90 degrees from the motor.
      - .. image:: media/missing.jpg
            :width: 200 px
    * - 4
      - Align the steering assembly and the servo such that the bolt in the servo arm is in the groove of the steering assembly and the body of the steering assembly rests on top of the servo mounting points. Note the orientation of the servo arm in relation to the motor leads in the figure.
      - .. image:: media/assembled_servo.jpg
            :width: 200 px
    * - 5
      - Using the screws provided with the servo, mount the servo assembly onto the base plate.
      - .. image:: media/mounted_servo_assembly.jpg
            :width: 200 px
    
The servo assembly is now complete. 

  .. list-table:: Part 5 - Mounting the drive assembly and wheels
    :widths: 5 25 50
    :header-rows: 0
    :align: center

    * - 1
      - Obtain the parts for this step: base, drive assembly, drive support, four M3-8 screws, wheels, 8 washers, 8 bearings (note, only four are shown in the picture because the remaining are already in the wheels), 2 M3-12 bolts and 2 M3-30 bolts.
      - .. image:: media/mounting_drive_assembly.jpg
          :width: 200 px
    * - 2
      - Position the drive support and drive assembly on the back of the base plate.
      - .. image:: media/drive_mount.jpg
          :width: 200 px
    * - 3
      - Attach the drive mount to the base using the four M3-8 screws. Note that this step can be tricky. First, make sure that the holes in the motor frame align with the rest of the holes in the support and base. You may need to squeeze some pieces together. Second, be sure that the bolts screw into these arms. It is recommended that you insert screws in opposite holes first as shown in the figure.
      - .. image:: media/missing.jpg
          :width: 200 px
    * - 4
      - Insert bearings into the wheels. Each wheel receives two bearings. Sometimes, it is helpful to use a long bolt to ensure that the bearings are aligned on the same axis. 
      - .. image:: media/bearings.jpg
          :width: 200 px
    * - 5 
      - Add a washer to each side of each wheel and insert the M3-12 bolts into the front (non-geared) wheels and the M3-30 bolts for the rear wheels.
      - .. image:: media/washer.jpg
          :width: 200 px
    * - 6
      - Lastly, attach the wheels. Screw them in enough to secure them to the base, but the must be able to move freely
      - .. image:: media/finished.jpg
          :width: 200 px



Next steps
----------


