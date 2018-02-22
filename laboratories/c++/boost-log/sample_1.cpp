# include <cstdint>

# include <atomic>
# include <iostream>

# include <boost/log/attributes/mutable_constant.hpp>
# include <boost/log/core.hpp>
# include <boost/log/exceptions.hpp>
# include <boost/log/keywords/log_name.hpp>
# include <boost/log/sinks/text_file_backend.hpp>
# include <boost/log/sources/global_logger_storage.hpp>
# include <boost/log/sources/logger.hpp>
# include <boost/log/sources/record_ostream.hpp>
# include <boost/log/sources/severity_logger.hpp>
# include <boost/log/trivial.hpp>
# include <boost/log/utility/setup/common_attributes.hpp>
# include <boost/log/utility/setup/file.hpp>

// https://stackoverflow.com/questions/22095667/how-to-log-line-number-of-coder-in-boost-log-2-0

void
doDirtyWork
(
    ::boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> * logger,
    std::string const & fileName,
    intmax_t lineNumber,
    std::string const & string
)
{
    ::boost::log::attribute_set attribute_set = logger->get_attributes();

    ::boost::log::attribute_set::iterator iterator;

    {
        iterator = attribute_set.find("FileName");

        if (iterator != attribute_set.end())
        {
            ::boost::log::attributes::mutable_constant<std::string> * mutable_constant = (::boost::log::attributes::mutable_constant<std::string> *)(& (iterator->second));

            mutable_constant->set(fileName);
        }
        else
        {
            ::boost::log::attributes::mutable_constant<std::string> mutable_constant(fileName);

            attribute_set.insert("FileName", mutable_constant);
        }
    }
    
    {
        iterator = attribute_set.find("LineNumber");

        if (iterator != attribute_set.end())
        {
            ::boost::log::attributes::mutable_constant<intmax_t> * mutable_constant = (::boost::log::attributes::mutable_constant<intmax_t> *)(& (iterator->second));

            mutable_constant->set(lineNumber);
        }
        else
        {
            ::boost::log::attributes::mutable_constant<intmax_t> mutable_constant(lineNumber);

            attribute_set.insert("LineNumber", mutable_constant);
        }
    }

    for (boost::log::attribute_set::iterator begin = attribute_set.begin(); begin != attribute_set.end(); ++ begin)
    {
        std::cout << begin->first << " ";//<< begin->second.get_value() << std::endl;
    }
    std::cout << std::endl;

    //BOOST_LOG(* logger) << "haha";

    //boost::log::sources::severity_logger_mt<int> severity_logger;
    BOOST_LOG_SEV(* logger, boost::log::trivial::info) << string;
}

int main()
{
    boost::log::add_file_log("sample.log");
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
    boost::log::sources::logger_mt logger;
    //logger.add_attribute("LineNumber", boost::log::attributes::counter<intmax_t>());
    //logger.add_attribute("LoggerName", boost::log::attributes::constant{})
    boost::log::sources::severity_logger_mt<int> severity_logger;
   // doDirtyWork(&logger, __FILE__, __LINE__, "all men must die.");
   
    boost::log::attribute_set abc;
    boost::log::attribute_value_set aaaa;
    boost::log::add_common_attributes(); /*
    logger.open_record((boost::log::keywords::severity = 1, boost::log::keywords::file_name = "GUI"));

    boost::log::attribute_set attribute_set = logger.get_attributes();
    boost::log::attribute_set::iterator iterator = attribute_set.find("LineNumber");
    if (iterator != attribute_set.end())
    {
        boost::log::attributes::mutable_constant<intmax_t> * haha = (boost::log::attributes::mutable_constant<intmax_t> *)(& (iterator->second));
        haha->set(__LINE__);
    }
    else
    {
        //attribute_set.insert("LineNumber", boost::log::attributes::mutable_constant<intmax_t>{__LINE__});
    }

    //severity_level a;

    //logger.add_attribute()
    */

    boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> & ddddd = boost::log::trivial::logger::get();

    doDirtyWork(& ddddd, __FILE__, __LINE__, "all men must die.");

    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

    BOOST_LOG(logger) << "nima" << std::endl;

    BOOST_LOG_SEV(severity_logger, boost::log::trivial::info) << "nima";

    //BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, boost::log::sources::logger_mt);

    return 0;
}
