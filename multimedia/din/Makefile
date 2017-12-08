# $FreeBSD$

PORTNAME=	din
PORTVERSION=	29
CATEGORIES=	multimedia
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	DIN Is Noise is an open source, cross-platform sound \
		synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libasound.so:audio/alsa-lib \
		libjack.so:audio/jack \
		libtcl${TCL_SHLIB_VER}.so:lang/tcl${TCL_SHLIB_VER} \
		libSDL.so:devel/sdl12 \
		libGL.so:graphics/mesa-libs

USES=		autoreconf tcl:86+

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tcl${TCL_VER}

LIBS+=		-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER} -lthr

PLIST=		${PKGDIR}/pkg-plist

#
# Sound server options
# ---
# To use alsa: make SOUND_SERVER=alsa
# To use jack: make SOUND_SERVER=jack
#
# If not set, jack is the default sound server
#
.if defined(SOUND_SERVER)
. if ${SOUND_SERVER} == alsa
CXXFLAGS+=	-D__LINUX_ALSA__
. endif
. if ${SOUND_SERVER} == jack
CXXFLAGS+=	-D__UNIX_JACK__
. endif
.else
CXXFLAGS+=	-D__UNIX_JACK__
.endif

pre-patch:
	@${MV} ${WRKSRC}/src/factory/country/Cocos_\(Keeling\)_Islands ${WRKSRC}/src/factory/country/Cocos__Keeling__Islands
	@${MV} ${WRKSRC}/src/factory/country/Falkland_Islands_\(Malvinas\) ${WRKSRC}/src/factory/country/Falkland_Islands__Malvinas_
	@${MV} ${WRKSRC}/src/factory/country/Holy_See_\(Vatican_City\) ${WRKSRC}/src/factory/country/Holy_See__Vatican_City_
	@${MV} ${WRKSRC}/src/factory/country/Iran_\(Islamic_Republic_of\) ${WRKSRC}/src/factory/country/Iran__Islamic_Republic_of_
	@${MV} ${WRKSRC}/src/factory/country/Cote_d\'Ivoire ${WRKSRC}/src/factory/country/Cote_d_Ivoire
	@${MV} ${WRKSRC}/src/factory/country/Korea,_Democratic_People\'s_Republic_of ${WRKSRC}/src/factory/country/Korea,_Democratic_People_s_Republic_of
	@${MV} ${WRKSRC}/src/factory/country/Lao_People\'s_Democratic_Republic ${WRKSRC}/src/factory/country/Lao_People_s_Democratic_Republic

#
# To roll snapshot: make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:devel/subversion
SVN_REV=	351
SVNROOT_URI=	svn://jagernot.website/home/svn/din

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI}/wip ${WRKSRC}
	cd ${WRKDIR}; tar cvfz ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.gz
#	scp -p ${DISTDIR}/${DISTNAME}.tar.gz \
#		freefall.freebsd.org:public_distfiles/
.endif # defined(BOOTSTRAP)

.include <bsd.port.post.mk>
