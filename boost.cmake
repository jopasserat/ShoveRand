
find_package( Boost 1.46 )

if ( NOT Boost_FOUND  )
	message( STATUS "Boost could not be found." )
   set( BOOST_ROOT ${BOOST_ROOT} CACHE PATH "Please enter path to Boost include folder." FORCE )
endif ()

message( STATUS "Boost_INCLUDE_DIRS : '" ${Boost_INCLUDE_DIRS} "'" )
