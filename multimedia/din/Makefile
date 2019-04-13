# $FreeBSD: head/multimedia/din/Makefile 498698 2019-04-12 06:36:31Z jbeich $

PORTNAME=	din
PORTVERSION=	39.0.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	Open source, cross-platform sound synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libasound.so:audio/alsa-lib \
		libjack.so:audio/jack

USES=		autoreconf tcl:86+ gl gnome
USE_GL=		gl
USE_SDL=	sdl

GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	JACK ALSA
OPTIONS_DEFAULT=	JACK

JACK_DESC=	Uses JACK sound server
ALSA_DESC=	Uses ALSA sound server

ALSA_CXXFLAGS+=	-D__LINUX_ALSA__
JACK_CXXFLAGS+=	-D__UNIX_JACK__

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tcl${TCL_VER}
LIBS+=		-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER} -lthr

.include <bsd.port.mk>
