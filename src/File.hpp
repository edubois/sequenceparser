#ifndef _SEQUENCE_PARSER_FILE_HPP_
#define _SEQUENCE_PARSER_FILE_HPP_

#include <FileObject.hpp>

namespace sequenceParser
{

class File : public FileObject
{
public:

    File(const boost::filesystem::path& directory, const std::string& filename, const EMaskOptions& options) :
	FileObject(directory, eMaskTypeFile, options),
	_filename ( filename )
    { }

    ~File()
    { }

public:
    std::ostream&                        getCout ( std::ostream& os ) const ;

    std::vector<boost::filesystem::path> getFiles() const;

    inline std::string                   getAbsoluteFilename() const
    {
        return (getAbsoluteDirectory() / _filename).string();
    }

    inline void                          clear()
    {
        FileObject::clear();
        _filename.clear();
    }

private:
    std::string _filename;
};

}

#endif
