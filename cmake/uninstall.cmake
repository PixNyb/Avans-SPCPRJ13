# Get the install manifest
file(READ "install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

# Iterate over the files and remove them
foreach(file ${files})
    message(STATUS "Removing '${file}'")

    if(EXISTS "${file}")
        file(REMOVE "${file}")
    else()
        message(STATUS "File '${file}' does not exist.")
    endif()
endforeach()