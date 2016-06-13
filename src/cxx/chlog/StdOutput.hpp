/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_STDOUTPUT_HPP_
#define CHAOSLOG_STDOUTPUT_HPP_

#include "chlog/AbstractOutput.hpp"

namespace chlog
{

/*!
 * \brief TODO:
 */
class StdOutput : public chlog::AbstractOutput
{
public:

    //--------------------------------------------------------------------------
    //                                ENUMERATORS
    //--------------------------------------------------------------------------

    /*!
     * \brief Enumerator that signifies whether ANSI escape sequence should be
     *        used to decorate text outputted to ```std::cout``` and
     *        ```std::cerr```.
     */
    enum UseANSI
    {
        /// ANSI escape sequences are never used to decorate output text.
        USEANSI_NEVER = 0,
        /// ANSI escape sequences are always used to decorate output text.
        USEANSI_ALWAYS,
        /// ANSI escape sequences are used to decorate output text if the
        /// current operating system's default shell supports them. For example
        /// ANSI escape sequences will be used on Linux systems but not on
        /// Windows systems.
        USEANSI_IF_SUPPORTED
    };

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO:
     */
    StdOutput(UseANSI use_ansi = USEANSI_IF_SUPPORTED);

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    // override
    virtual void write(
            chlog::Verbosity verbosity,
            const chlog::Profile& profile,
            const chaos::str::UTF8String& message);

private:

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Whether ANSI escape sequences should be used or not.
     */
    UseANSI m_use_ansi;
};

} // namespace chlog

#endif