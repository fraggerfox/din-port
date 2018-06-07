# $FreeBSD$

PORTNAME=	din
PORTVERSION=	30
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

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=JACK ALSA
OPTIONS_DEFAULT=	JACK

JACK_DESC=	Uses JACK sound server
ALSA_DESC=	Uses ALSA sound server

ALSA_CXXFLAGS+=	-D__LINUX_ALSA__
JACK_CXXFLAGS+=	-D__UNIX_JACK__

.include <bsd.port.pre.mk>

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tcl${TCL_VER}

LIBS+=		-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER} -lthr

PLIST=		${PKGDIR}/pkg-plist

#
# To roll snapshot: make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:devel/subversion
SVN_REV=	375
SVNROOT_URI=	svn://jagernot.website/home/svn/din

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI}/wip ${WRKSRC}
	cd ${WRKDIR}; tar cvfz ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.gz
	scp -p ${DISTDIR}/${DISTNAME}.tar.gz \
		freefall.freebsd.org:public_distfiles/
.endif # defined(BOOTSTRAP)

.include <bsd.port.post.mk>
