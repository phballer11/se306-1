define pickerLaser ranger 
( 
  sensor( range [ 0 3 ] fov 60 samples 60 ) 
    size [0.100 0.100 0.100] 
      color "black" 
        block( 
            points 4 
                point[0] [0 0] 
                    point[1] [0.1 0] 
                        point[2] [0.1 0.1] 
                            point[3] [0 0.1] 
                                z [0 0.1] 
                                    ) 
        ) 

define carrier actor
( 
	#body
  	model
	(
		size [1 0.6 0.3]
		pose [0 0 0 0.0]
		color "orange"
	)
	#Carrier Logo "CA" at front
	#C LETTER
	model
	(
		size [0.01 0.1 0.05]
		pose [0.5 -0.10 0.2 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.01 0.14]
		pose [0.5 -0.15 0.06 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.1 0.05]
		pose [0.5 -0.10 0.06 0.0]
		color "black"
	)
	#A LETTER
	model
	(
		size [0.01 0.1 0.05]
		pose [0.5 0.12 0.2 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.1 0.05]
		pose [0.5 0.12 0.1 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.01 0.2]
		pose [0.5 0.07 0.06 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.01 0.2]
		pose [0.5 0.17 0.06 0.0]
		color "black"
	)

	#CA logo at back
	model
	(
		size [0.01 0.1 0.05]
		pose [-0.5 0.10 0.2 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.01 0.14]
		pose [-0.5 0.15 0.06 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.1 0.05]
		pose [-0.5 0.10 0.06 0.0]
		color "black"
	)
	#A LETTER
	model
	(
		size [0.01 0.1 0.05]
		pose [-0.5 -0.09 0.2 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.1 0.05]
		pose [-0.5 -0.09 0.1 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.01 0.2]
		pose [-0.5 -0.13 0.06 0.0]
		color "black"
	)
	model
	(
		size [0.01 0.01 0.2]
		pose [-0.5 -0.03 0.06 0.0]
		color "black"
	)

	pickerLaser(pose [ 0.0 0.0 0.5 0.0 ])
	
	#right arm
	model
	(
		size [0.15 0.1 0.5]
		pose [0 -0.3 0.3 0]
		color "white"
	)
	#left arm
	model
	(
		size [0.15 0.1 0.5]
		pose [0 0.3 0.3 0]
		color "white"
        )
	
	#head
	model
	(
		size [0.3 0.3 0.3]
		pose [0 0 0.35 0]
		color "white"
	)
	model
	(
		size [0.3 0.20 0.05]
		pose [0 0 0.65 0]
		color "white"
	)
	
	#neck
	model
	(
		size [0.3 0.25 0.05]
		pose [0 0 0.30 0]
		color "white"
	)

	#right ear
	model
	(
		size [0.27 0.05 0.2]
		pose [0 -0.16 0.45 0]
		color "white"
	)
	model
	(
		size [0.2 0.05 0.15]
		pose [0 -0.2 0.45 0]
		color "white"
	)
	
	#left ear
	model
	(
		size [0.27 0.05 0.2]
		pose [0 0.16 0.45 0]
		color "white"
	)
	model
	(
		size [0.2 0.05 0.15]
		pose [0 0.2 0.45 0]
		color "white"
	)

	#right eye
	model
	(
		size [0.02 0.02 0.02]
		pose [0.18 -0.035 0.55 0]
		color "black"
	)
	
	#left eye
	model
	(
		size [0.02 0.02 0.02]
		pose [0.18 0.035 0.55 0]
		color "black"
	)

	#mouth
	model
	(
		size [0.02 0.15 0.01]
		pose [0.18 0 0.43 0]
		color "black"
	)
	
	model
	(
		size [0.01 0.01 0.07]
		pose [0.18 0.09 0.43 0]
		color "black"
	)
	model
	(
		size [0.01 0.01 0.07]
		pose [0.18 -0.09 0.43 0]
		color "black"
	)

	
	
	
	
	
	
	
	
	
	
	
	
	
	
) 
