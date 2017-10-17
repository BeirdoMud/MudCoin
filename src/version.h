// Copyright (c) 2012 The Bitcoin developers
// Copyright (c) 2012-2013 The PPCoin developers
// Copyright (c) 2017 MudCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef MUDCOIN_VERSION_H
#define MUDCOIN_VERSION_H

#include <string>

//
// client versioning
//

// These need to be macros, as version.cpp's voodoo requires it
#define CLIENT_VERSION_MAJOR       0
#define CLIENT_VERSION_MINOR       6
#define CLIENT_VERSION_REVISION    3
#define CLIENT_VERSION_BUILD       0

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR 
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

// mudcoin version - intended for display purpose ONLY
#define MUDCOIN_VERSION_MAJOR       0
#define MUDCOIN_VERSION_MINOR       5
#define MUDCOIN_VERSION_REVISION    4
#define MUDCOIN_VERSION_BUILD       0

static const int MUDCOIN_VERSION =
                           1000000 * MUDCOIN_VERSION_MAJOR
                         +   10000 * MUDCOIN_VERSION_MINOR
                         +     100 * MUDCOIN_VERSION_REVISION
                         +       1 * MUDCOIN_VERSION_BUILD;

//
// network protocol versioning
//

static const int PROTOCOL_VERSION = 60006;

// earlier versions not supported as of Feb 2012, and are disconnected
// NOTE: as of mudcoin v0.6 message serialization (vSend, vRecv) still
// uses MIN_PROTO_VERSION(209), where message format uses PROTOCOL_VERSION
static const int MIN_PROTO_VERSION = 209;

// nTime field added to CAddress, starting with this version;
// if possible, avoid requesting addresses nodes older than this
static const int CADDR_TIME_VERSION = 31402;

// only request blocks from nodes outside this range of versions
static const int NOBLKS_VERSION_START = 32000;
static const int NOBLKS_VERSION_END = 32400;

// BIP 0031, pong message, is enabled for all versions AFTER this one
static const int BIP0031_VERSION = 60000;

#endif
