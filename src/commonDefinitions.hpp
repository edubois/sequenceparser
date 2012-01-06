#ifndef COMMON_DEFINITIONS_HPP
#define COMMON_DEFINITIONS_HPP

#ifndef PROPERTIES_WIDTH
#define PROPERTIES_WIDTH 3
#endif

#ifndef NAME_WIDTH
#define NAME_WIDTH 50
#endif

#ifndef NAME_WIDTH_WITH_DIR
#define NAME_WIDTH_WITH_DIR 80
#endif

#ifdef __LINUX__
static const std::string kColorStd      ( "\E[0;0m" );
static const std::string kColorFolder   ( "\E[1;34m" );
static const std::string kColorFile     ( "\E[0;32m" );
static const std::string kColorSequence ( "\E[0;32m" );
static const std::string kColorError    ( "\E[1;31m" );
#else
static const std::string kColorStd      ("");
static const std::string kColorFolder   ("");
static const std::string kColorFile     ("");
static const std::string kColorSequence ("");
static const std::string kColorError    ("");
#endif

namespace sequenceParser {

/**
 * List all recognized pattern types.
 */
enum EMaskType {
    eMaskTypeUndefined       = 0,
    eMaskTypeDirectory       = 1,
    eMaskTypeFile            = eMaskTypeDirectory       * 2,
    eMaskTypeSequence        = eMaskTypeFile            * 2,
    eMaskTypeDefault         = eMaskTypeSequence
};

enum EMaskOptions {
    eMaskOptionsNone         = 0,                            // 0
    eMaskOptionsProperties   = 1,                            // show type of FileObject
    eMaskOptionsPath         = eMaskOptionsProperties   * 2, // show path of FileObject
    eMaskOptionsAbsolutePath = eMaskOptionsPath         * 2, // show absolute path of FileObject
    eMaskOptionsDotFile      = eMaskOptionsAbsolutePath * 2, // show files which start with a dot (hidden files)
    eMaskOptionsColor        = eMaskOptionsDotFile      * 2, // output with color
    eMaskOptionsDefault      = ( eMaskOptionsPath | eMaskOptionsColor )
};

inline EMaskType operator~(const EMaskType& a) {
    EMaskType b = (EMaskType) (~int(a));
    return b;
}

inline EMaskType operator&=(EMaskType& a, const EMaskType& b) {
    a = (EMaskType) (int(b) & int(a));
    return a;
}

inline EMaskType operator|=(EMaskType& a, const EMaskType& b) {
    a = (EMaskType) (int(b) | int(a));
    return a;
}

inline EMaskOptions operator|=(EMaskOptions& a, const EMaskOptions& b) {
    a = (EMaskOptions) (int(b) | int(a));
    return a;
}

inline EMaskOptions remove(EMaskOptions& a, const EMaskOptions& b) {
    a = (EMaskOptions) (int(~b) & int(a));
    return a;
}

typedef std::size_t Time;

template<typename T>
T greatestCommonDivisor(T a, T b)
{
    T r;
    if( b == 0 ) return 0;
    while ((r = a % b) != 0)
    {
	a = b;
	b = r;
    }
    return b;
}

}

#endif