# - Find Crypto++

if(Crypto++_INCLUDE_DIRS AND Crypto++_LIBRARIES)
   set(Crypto++_FOUND TRUE)

else(Crypto++_INCLUDE_DIRS AND Crypto++_LIBRARIES)
  find_path(Crypto++_INCLUDE_DIRS cryptlib.h
      /usr/include/crypto++
      /usr/include/cryptopp
      /usr/local/include/crypto++
      /usr/local/include/cryptopp
      /opt/local/include/crypto++
      /opt/local/include/cryptopp
      $ENV{SystemDrive}/Crypto++/include
      )

  find_library(Crypto++_LIBRARIES NAMES cryptopp
      PATHS
      /usr/lib
      /usr/local/lib
      /opt/local/lib
      $ENV{SystemDrive}/Crypto++/lib
      )

  if(Crypto++_INCLUDE_DIRS AND Crypto++_LIBRARIES)
    set(Crypto++_FOUND TRUE)
    message(STATUS "Found Crypto++: ${Crypto++_INCLUDE_DIRS}, ${Crypto++_LIBRARIES}")
  else(Crypto++_INCLUDE_DIRS AND Crypto++_LIBRARIES)
    set(Crypto++_FOUND FALSE)
		if (Crypto++_FIND_REQUIRED)
			message(FATAL_ERROR "Crypto++ is required but not found!")
		else(Crypto++_FIND_REQUIRED)
 	  	message(STATUS "Crypto++ not found.")
		endif(Crypto++_FIND_REQUIRED)
  endif(Crypto++_INCLUDE_DIRS AND Crypto++_LIBRARIES)

  mark_as_advanced(Crypto++_INCLUDE_DIR Crypto++_LIBRARIES)

endif(Crypto++_INCLUDE_DIRS AND Crypto++_LIBRARIES)
