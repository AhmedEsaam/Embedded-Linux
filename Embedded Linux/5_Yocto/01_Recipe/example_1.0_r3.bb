SUMMARY = "This is my recipe"
DESCRIPTION = "this recipe do nothing"

License = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=08..."

########## If Sources in git ############
# fetching the source from the (github, local, http server) 
#SRC_URI = "git://github.com/...;protocol=https;branch=main"

# Checksum specific commit ONLY used in GIT
#SRC_REV = "545845374537435458345388743145837453435"

######## If Sources are local ###########
# it's impact on SRC_URI
FILESPATH:append = " :${THISDIR}/ahmed:"

SRC_URI = "file://main.c"

# if you want to write a python function
python do_configure(){
    machine = d.getVar('MACHINE')
    bb.plain(f"******** {machine} ********")
}

# Override a default python task in the generated python code file by bitbake
# You can see it if you expanded this file using `bitbake -e recipe_name`
# Note: this is not a python function itself, it gets parsed by the bitbake to a python task
do_compile () {
    ${CC} ${CFLAGS} -static ${WORKDIR}/main.c -o ${B}/myapp
    # or just use cmake (for x86) to build
    # in (rpbi) it's not cmake
    cmake -S . -B ${B}
}

do_install(){
    mkdir -p ${D}${bindir}
    cp ${B}/myapp ${D}${bindir}
}
