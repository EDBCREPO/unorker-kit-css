#pragma once

namespace uk { 

    express_tcp_t padding() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            for( auto& size: map_t<string_t,int>({ 
                { nullptr,   0 },
                { "\\@s",  640 },
                { "\\@m",  960 },
                { "\\@l", 1200 },
                { "\\@2l",1600 }
            }).data() ){

                if( size.first != nullptr ){
                    cli.write( regex::format( _STRING_(
                       @media( min-width: ${0}px ) {
                    ), size.second ));
                }

                for( auto& item : map_t<string_t,string_t>({
                    { "none",    "0px"  },
                    { "2xsmall", "5px"  },
                    { "xsmall",  "10px" },
                    { "small",   "15px" },
                    { "medium",  "25px" },
                    { "large",   "30px" },
                    { "xlarge",  "35px" },
                    { "2xlarge", "40px" }
                }).data() ){
                    cli.write( regex::format( _STRING_ (
                       .uk-child-padding-${0}${2}>:not([class*="uk-padding"]){ padding:${1}; } 
                       .uk-padding-${0}${2}                                  { padding:${1}; }
                    ), item.first, item.second, size.first ));
                }

                cli.write( regex::format( _STRING_ (

                    .uk-padding-remove-bottom${0} { padding-bottom: 0px; }
                    .uk-padding-remove-top${0}    { padding-top:    0px; }
                    .uk-padding-remove-left${0}   { padding-left:   0px; }
                    .uk-padding-remove-right${0}  { padding-right:  0px; }

                    .uk-padding-remove-horizontal${0} {
                        padding-left:  0px;
                        padding-right: 0px;
                    }

                    .uk-padding-remove-vertical${0} {
                        padding-top:    0px;
                        padding-bottom: 0px;
                    }

                    .uk-padding-remove${0} {
                        padding-left:   0px;
                        padding-right:  0px;
                        padding-top:    0px;
                        padding-bottom: 0px;
                    }
                    
                    .uk-child-padding${0}>:not([class*="uk-padding"]){ padding:20px; }
                    .uk-padding${0}                                  { padding:20px; }

                ), size.first ));

                if( size.first != nullptr ){ cli.write( "}" ); }

            }

        });

        return app;
    }

}